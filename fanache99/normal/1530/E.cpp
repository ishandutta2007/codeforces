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
#include <complex>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100000;
const int SIGMA = 26;

char s[1 + MAXN], t[1 + MAXN + 1];
int fr[SIGMA];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        memset(fr, 0, sizeof(fr));
        for (int i = 1; i <= n; i++) {
            fr[s[i] - 'a']++;
        }
        bool found1 = false;
        bool foundAll = false;
        int small = -1;
        int l = 0;
        for (int i = 0; i < SIGMA; i++) {
            if (fr[i] == 1) {
                found1 = true;
                t[++l] = 'a' + i;
                fr[i]--;
                for (int j = 0; j < SIGMA; j++) {
                    while (fr[j] > 0) {
                        t[++l] = 'a' + j;
                        fr[j]--;
                    }
                }
                break;
            }
            if (fr[i] == n) {
                foundAll = true;
                for (int j = 1; j <= n; j++) {
                    t[++l] = 'a' + i;
                }
                break;
            }
            if (fr[i] > 0 && small == -1) {
                small = i;
            }
        }
        if (!found1 && !foundAll) {
            if (n - fr[small] >= fr[small] - 2) {
                t[++l] = 'a' + small;
                t[++l] = 'a' + small;
                fr[small] -= 2;
                int p = small + 1;
                while (l < n) {
                    while (p < SIGMA && fr[p] == 0) {
                        p++;
                    }
                    assert(p < SIGMA);
                    t[++l] = 'a' + p;
                    fr[p]--;
                    if (fr[small] != 0) {
                        t[++l] = 'a' + small;
                        fr[small]--;
                    }
                }
            } else {
                int small2 = small + 1;
                while (small2 < SIGMA && fr[small2] == 0) {
                    small2++;
                }
                assert(small2 < SIGMA);
                if (fr[small] + fr[small2] == n) {
                    t[++l] = 'a' + small;
                    fr[small]--;
                    while (fr[small2] > 0) {
                        t[++l] = 'a' + small2;
                        fr[small2]--;
                    }
                    while (fr[small] > 0) {
                        t[++l] = 'a' + small;
                        fr[small]--;
                    }
                } else {
                    int small3 = small2 + 1;
                    while (small3 < SIGMA && fr[small3] == 0) {
                        small3++;
                    }
                    assert(small3 < SIGMA);
                    t[++l] = 'a' + small;
                    fr[small]--;
                    t[++l] = 'a' + small2;
                    fr[small2]--;
                    while (fr[small] > 0) {
                        t[++l] = 'a' + small;
                        fr[small]--;
                    }
                    t[++l] = 'a' + small3;
                    fr[small3]--;
                    for (int i = 0; i < SIGMA; i++) {
                        while (fr[i] > 0) {
                            t[++l] = 'a' + i;
                            fr[i]--;
                        }
                    }
                }
            }
        }
        t[n + 1] = 0;
        cout << (t + 1) << "\n";
    }
    return 0;
}