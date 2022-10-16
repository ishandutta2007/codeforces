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
const int MOD = 998244353;

int v[1 + MAXN];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

struct S {
    int x;
    int cnt;
    int sum;
};

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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int ans = 0;
//        for (int r = 1; r <= n; r++) {
//            int x = v[r];
//            int tot = 0;
//            for (int l = r - 1; l >= 1; l--) {
//                int y = v[l];
//                if (y > x) {
//                    if (y % x == 0) {
//                        add(tot, y / x - 1);
//                    } else {
//                        int t = y / x + 1;
//                        add(tot, t - 1);
//                        x = y / t;
//                    }
//                } else {
//                    x = y;
//                }
//                add(ans, tot);
//            }
//        }
        vector<S> w = {{v[n], 1, 0}};
        for (int l = n - 1; l >= 1; l--) {
            vector<S> u;
            bool done = false;
            for (auto [x, cnt, sum] : w) {
                int y = v[l];
                S s;
                if (y > x) {
                    if (y % x == 0) {
                        s = {x, cnt, (int) ((sum + 1LL * cnt * (y / x - 1)) % MOD)};
                    } else {
                        int t = y / x + 1;
                        s = {y / t, cnt, (int) ((sum + 1LL * cnt * (t - 1)) % MOD)};
                    }
                } else {
                    s = {y, cnt, sum};
                }
                if (!done && s.x >= v[l]) {
                    u.push_back({v[l], 1, 0});
                    done = true;
                }
                if (!u.empty()) {
                    assert(s.x >= u.back().x);
                    if (s.x > u.back().x) {
                        u.push_back(s);
                    } else {
                        u.back().cnt += s.cnt;
                        add(u.back().sum, s.sum);
                    }
                } else {
                    u.push_back(s);
                }
            }
            if (!done) {
                u.push_back({v[l], 1, 0});
            }
//            reverse(u.begin(), u.end());
            w = u;
            for (auto [x, cnt, sum] : w) {
                add(ans, sum);
            }
        }
        int aux = 0;
        for (auto [x, cnt, sum] : w) {
            aux += cnt;
        }
        assert(aux == n);
        cout << ans << "\n";
    }
    return 0;
}