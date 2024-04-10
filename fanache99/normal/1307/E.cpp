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

const int MAXN = 5000;
const int MOD = 1000000007;

int v[1 + MAXN], f[1 + MAXN], h[1 + MAXN];
vector<int> where[1 + MAXN];
bool fromLeft[1 + MAXN], fromRight[1 + MAXN];
int fr[1 + MAXN], cnt[1 + MAXN][1 + MAXN], cows[1 + MAXN][1 + MAXN];
vector<int> cow[1 + MAXN];

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return answer;
}

void update(int &best, int &sum, int bestNow, int sumNow) {
    if (bestNow > best) {
        best = bestNow;
        sum = sumNow;
    } else if (bestNow == best) {
        sum = (sumNow + sum) % MOD;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        where[v[i]].push_back(i);
        for (int j = 1; j <= n; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][v[i]]++;
    }
    fromLeft[0] = true;
    for (int i = 1; i <= k; i++) {
        cin >> f[i] >> h[i];
        cow[f[i]].push_back(h[i]);
        cows[f[i]][h[i]]++;
        if (h[i] <= where[f[i]].size()) {
            fromLeft[where[f[i]][h[i] - 1]] = true;
            fromRight[where[f[i]][where[f[i]].size() - h[i]]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cows[i][j] += cows[i][j - 1];
        }
    }
    int best = 0, sum = 1;
    {
        int now = 0, total = 1;
        for (int i = 1; i <= n; i++) {
            if (cows[i][cnt[n][i]] > 0) {
                now++;
                total = 1LL * total * cows[i][cnt[n][i]] % MOD;
            }
        }
        update(best, sum, now, total);
    }
    for (int i = 1; i <= n; i++) {
        if (fromLeft[i]) {
            int now = 1, total = 1;
            {
                int r = cnt[n][v[i]] - cnt[i][v[i]];
                int x = cows[v[i]][r];
                if (r >= cnt[i][v[i]]) {
                    x--;
                }
                if (x > 0) {
                    now++;
                    total = 1LL * total * x % MOD;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (j != v[i]) {
                    int l = cnt[i][j], r = cnt[n][j] - cnt[i][j];
                    int a = cows[j][l], b = cows[j][r];
                    if (a > b) {
                        swap(a, b);
                    }
                    if (b >= 2 && a >= 1) {
                        now += 2;
                        total = 1LL * total * a % MOD * (b - 1) % MOD;
                    } else if (a >= 1 || b >= 1) {
                        now++;
                        total = 1LL * total * (b + a) % MOD;
                    }
                }
            }
            update(best, sum, now, total);
        }
    }
    if (best == 0) {
        sum = 1;
    }
    cout << best << " " << sum << "\n";
    return 0;
}