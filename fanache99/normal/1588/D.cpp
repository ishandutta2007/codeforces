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

const int MAXN = 10;
const int SIGMA = 52;

int fst[MAXN][SIGMA], snd[MAXN][SIGMA];
int dp[1 << MAXN][SIGMA];
vector<pair<int, int> > g[1 << MAXN][SIGMA];
pair<int, int> dad[1 << MAXN][SIGMA];

int code(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    } else {
        assert(ch >= 'A' && ch <= 'Z');
        return ch - 'A' + SIGMA / 2;
    }
}

char decode(int x) {
    if (x >= 0 && x < SIGMA / 2) {
        return x + 'a';
    } else {
        assert(x >= SIGMA / 2 && x < SIGMA);
        return x + 'A' - SIGMA / 2;
    }
}

bool ok(int mask, int c, int n) {
    for (int i = 0; i < n; i++) {
        int bit = ((mask >> i) & 1);
        if ((bit == 0 && fst[i][c] == -1) || (bit == 1 && snd[i][c] == -1)) {
            return false;
        }
    }
    return true;
}

void upd(int &currDp, pair<int, int> &currDad, int newDp, pair<int, int> newDad) {
    if (newDp > currDp) {
        currDp = newDp;
        currDad = newDad;
    }
}

void transition(int mask, int c, int d, int n) {
    int newMask = 0;
    for (int i = 0; i < n; i++) {
        int bit = ((mask >> i) & 1);
        int pos = (bit ? snd[i][c] : fst[i][c]);
        int newBit = (fst[i][d] > pos ? 0 : (snd[i][d] > pos ? 1 : -1));
        if (newBit == -1) {
            return;
        }
        newMask += (1 << i) * newBit;
    }
    assert(ok(newMask, d, n));
    g[newMask][d].push_back({mask, c});
}

void compute(int mask, int c, int &ans, pair<int, int> &last) {
    if (dp[mask][c] != 0) {
        return;
    }
    upd(dp[mask][c], dad[mask][c], 1, {-1, -1});
    for (auto &it : g[mask][c]) {
        compute(it.first, it.second, ans, last);
        upd(dp[mask][c], dad[mask][c], dp[it.first][it.second] + 1, it);
    }
    upd(ans, last, dp[mask][c], {mask, c});
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            memset(fst[i], -1, sizeof(fst[i]));
            memset(snd[i], -1, sizeof(snd[i]));
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                int c = code(s[j]);
                if (fst[i][c] == -1) {
                    fst[i][c] = j;
                } else {
                    assert(snd[i][c] == -1);
                    snd[i][c] = j;
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        pair<int, int> last = {-1, -1};
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int c = 0; c < SIGMA; c++) {
                dp[mask][c] = 0;
                g[mask][c].clear();
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int c = 0; c < SIGMA; c++) {
                if (!ok(mask, c, n)) {
                    continue;
                }
                for (int d = 0; d < SIGMA; d++) {
                    transition(mask, c, d, n);
                }
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int c = 0; c < SIGMA; c++) {
                if (!ok(mask, c, n)) {
                    continue;
                }
                compute(mask, c, ans, last);
            }
        }
        string sol;
        while (last != make_pair(-1, -1)) {
            sol.push_back(decode(last.second));
            last = dad[last.first][last.second];
        }
        reverse(sol.begin(), sol.end());
        cout << ans << "\n" << sol << "\n";
    }
    return 0;
}