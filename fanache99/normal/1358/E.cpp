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

const int MAXN = 500000;

int v[1 + (MAXN + 1) / 2];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("alambicare.out");
    int n;
    cin >> n;
    int n1 = (n + 1) / 2, n2 = n - n1;
    long long sum = 0;
    for (int i = 1; i <= n1; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int x;
    cin >> x;
    if (x <= 0) {
        long long smallest = sum + 1LL * n2 * x;
        int i = 1;
        while (smallest <= 0 && i <= n1) {
            sum -= v[i];
            smallest -= x;
            smallest = min(smallest, sum + 1LL * n2 * x);
            i++;
        }
        if (smallest > 0) {
            cout << n - i + 1 << "\n";
        } else {
            cout << "-1\n";
        }
    } else {
        if (sum + 1LL * n2 * x > 0) {
            cout << n << "\n";
        } else {
            cout << "-1\n";
        }
    }
    timeEnd();
    //timeDuration();
    return 0;
}