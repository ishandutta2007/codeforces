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
#include <bitset>
#include <unordered_map>

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

const int MAXN = 200000;

char s[1 + MAXN], a[1 + MAXN + 1], b[1 + MAXN + 1];
vector<int> ones, zeros;

bool check(char t[], int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += (t[i] == '(' ? 1 : -1);
        if (s < 0) {
            return false;
        }
    }
    return (s == 0);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n >> (s + 1);
        zeros.clear();
        ones.clear();
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                zeros.push_back(i);
            } else {
                ones.push_back(i);
            }
        }
        if (ones.size() % 2 != 0) {
            cout << "NO\n";
        } else {
            for (int i = 0; i < ones.size() / 2; i++) {
                a[ones[i]] = b[ones[i]] = '(';
            }
            for (int i = ones.size() / 2; i < ones.size(); i++) {
                a[ones[i]] = b[ones[i]] = ')';
            }
            for (int i = 0; i < zeros.size(); i++) {
                if (i % 2 == 0) {
                    a[zeros[i]] = '(';
                    b[zeros[i]] = ')';
                } else {
                    a[zeros[i]] = ')';
                    b[zeros[i]] = '(';
                }
            }
            if (check(a, n) && check(b, n)) {
                a[n + 1] = b[n + 1] = 0;
                cout << "YES\n" << (a + 1) << "\n" << (b + 1) << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    //timeDuration();
    return 0;
}