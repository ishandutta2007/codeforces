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

const int MAXN = 17;
const int INF = 1000000000;

bool v[1 << MAXN];
int dp[1 << MAXN][1 + MAXN][2][2];

int compute(int l, int r, int level, bool winner, bool loser) {
    if (dp[l][level][winner][loser] != -1) {
        return dp[l][level][winner][loser];
    }
    int best = -INF;
    if (l + 1 == r) {
        assert(level == 1);
        if ((v[l] == winner && v[r] == loser) || (v[l] == loser && v[r] == winner)) {
            best = (winner || loser);
        }
    } else {
        int m = (l + r) / 2;
        for (int lWinner = 0; lWinner < 2; lWinner++) {
            for (int lLoser = 0; lLoser < 2; lLoser++) {
                for (int rWinner = 0; rWinner < 2; rWinner++) {
                    for (int rLoser = 0; rLoser < 2; rLoser++) {
                        int lBest = compute(l, m, level - 1, lWinner, lLoser);
                        int rBest = compute(m + 1, r, level - 1, rWinner, rLoser);
                        if (lBest == -INF || rBest == -INF) {
                            continue;
                        }
                        for (int upperWinner : {lWinner, rWinner}) {
                            int upperLoser = lWinner + rWinner - upperWinner;
                            if (upperWinner != winner) {
                                continue;
                            }
                            for (int lowerWinner: {lLoser, rLoser}) {
                                int lowerLoser = lLoser + rLoser - lowerWinner;
                                for (int newLowerWinner : {upperLoser, lowerWinner}) {
                                    int newLowerLoser = upperLoser + lowerWinner - newLowerWinner;
                                    if (newLowerWinner != loser) {
                                        continue;
                                    }
                                    best = max(best, lBest + rBest + (lWinner || rWinner) + (lLoser || rLoser) + (upperLoser || lowerWinner));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    dp[l][level][winner][loser] = best;
    return best;
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
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        v[x - 1] = true;
    }
    int answer = -INF;
    memset(dp, -1, sizeof(dp));
    for (int winner = 0; winner < 2; winner++) {
        for (int loser = 0; loser < 2; loser++) {
            answer = max(answer, compute(0, (1 << n) - 1, n, winner, loser) + (winner || loser));
        }
    }
    cout << answer << "\n";
    return 0;
}