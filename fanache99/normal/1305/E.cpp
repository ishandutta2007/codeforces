#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 5000;
const int MAXVAL = 1000000000;

int v[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n, m;
    cin >> n >> m;
    int i = 1, limit = 0;
    while (i <= n && limit + (i - 1) / 2 <= m) {
        limit += (i - 1) / 2;
        i++;
    }
    if (i > n) {
        if (limit < m) {
            cout << "-1\n";
            return 0;
        } else {
            for (int j = 1; j <= n; j++) {
                v[j] = j;
            }
        }
    } else {
        i--;
        for (int j = 1; j <= i; j++) {
            v[j] = j;
        }
        v[i + 1] = 2 * i + 1 - 2 * (m - limit);
        for (int j = i + 2; j <= n; j++) {
            v[j] = 100000001 + 10000 * j;
        }
    }
    for (int j = 1; j <= n; j++) {
        cout << v[j] << " ";
    }
    //timeDuration();
    return 0;
}