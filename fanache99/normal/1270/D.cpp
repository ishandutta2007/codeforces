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

const int MAXN = 500;

int val[MAXN];

int ask(vector<int> &v) {
    cout << "? ";
    for (auto it : v) {
        cout << it + 1 << " ";
    }
    cout << "\n";
    cout.flush();
    int pos, x;
    cin >> pos >> x;
    val[pos] = x;
    return pos;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, k;
    cin >> n >> k;
    int a = -1, b = -1, fa = 0, fb = 0;
    for (int i = 0; i <= k; i++) {
        vector<int> v;
        for (int j = 0; j < k; j++) {
            v.push_back((i + j) % (k + 1));
        }
        int pos = ask(v);
        if (a == -1 || pos == a) {
            a = pos;
            fa++;
        } else {
            b = pos;
            fb++;
        }
    }
    if (val[a] > val[b]) {
        swap(a, b);
        swap(fa, fb);
    }
    cout << "! " << fb << "\n";
    //timeDuration();
    return 0;
}