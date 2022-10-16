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
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

long long sum[1 + MAXN], v[1 + MAXN];
int st[1 + MAXN], fenwick[1 + MAXN];
vector<int> where[SIGMA];

int update(int x, int n) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x]++;
    }
}

int query(int x) {
    int ans = 0;
    for (; x > 0; x -= (x & -x)) {
        ans += fenwick[x];
    }
    return ans;
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        string ss = s;
        sort(ss.begin(), ss.end());
        if (ss >= t) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                where[s[i - 1] - 'a'].push_back(i);
                fenwick[i] = 0;
            }
            for (int i = 0; i < SIGMA; i++) {
                reverse(where[i].begin(), where[i].end());
            }
            long long ans = 1LL * n * n, sum = 0;
            for (int i = 1; i <= n; i++) {
                for (int ch = 0; ch < t[i - 1] - 'a'; ch++) {
                    if (where[ch].empty()) {
                        continue;
                    }
                    int p = where[ch].back();
                    ans = min(ans, sum + p - 1 - query(p - 1));
                }
                int ch = t[i - 1] - 'a';
                if (where[ch].empty()) {
                    break;
                }
                int p = where[ch].back();
                sum += p - 1 - query(p - 1);
                update(p, n);
                where[ch].pop_back();
            }
            cout << ans << "\n";
            for (int i = 0; i < SIGMA; i++) {
                where[i].clear();
            }
        }
    }
    return 0;
}