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

const int MAXN = 500000;
const int MAXVAL = 500000;

int v[1 + MAXN], need[1 + MAXVAL], have[1 + MAXVAL];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int m, k, n, s, diff = 0;
    cin >> m >> k >> n >> s;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= s; i++) {
        int x;
        cin >> x;
        if (need[x] == 0) {
            diff++;
        }
        need[x]++;
    }
    int limit = m - n * k;
    for (int i = m, j = m, ok = 0; i >= 1; i--) {
        have[v[i]]++;
        if (have[v[i]] == need[v[i]]) {
            ok++;
        }
        while (j >= i && have[v[j]] > need[v[j]]) {
            have[v[j]]--;
            j--;
        }
        if (ok == diff && i + k - 1 <= m) {
            int out = (i - 1) % k, l = j - i + 1;
            if (l > k) {
                out += l - k;
            }
            if (out <= limit) {
                vector<int> sol;
                for (int x = 1; x <= (i - 1) % k; x++) {
                    sol.push_back(x);
                }
                for (int p = i, x = 1; x <= l - k; x++) {
                    while (have[v[p]] == need[v[p]]) {
                        p++;
                    }
                    have[v[p]]--;
                    sol.push_back(p);
                    p++;
                }
                sort(sol.begin(), sol.end());
                cout << sol.size() << "\n";
                for (auto it : sol) {
                    cout << it << " ";
                }
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}