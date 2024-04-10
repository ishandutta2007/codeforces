//#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 16;
const int INF = 1000000000;

char color[MAXN];
int n, red[MAXN], blue[MAXN];
int dp[1 << MAXN][2][MAXN * MAXN + 1];
int redCards[1 << MAXN], blueCards[1 << MAXN];

void Precompute() {
    for (int i = 1; i < (1 << n); i++) {
        redCards[i] = redCards[i - (i & (-i))];
        blueCards[i] = blueCards[i - (i & (-i))];
        int bit = 0;
        while ((1 << bit) != (i & (-i)))
            bit++;
        if (color[bit] == 'R')
            redCards[i]++;
        else
            blueCards[i]++;
    }
}

int Solve(int mask, int noRed, int other) {
    other = min(other, n * n);
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[mask][noRed][other] != -1)
        return dp[mask][noRed][other];
    int answer = INF;
    for (int i = 0; i < n; i++)
        if (!(mask & (1 << i))) {
            int currentBlue = 0, currentRed = 0;
            if (noRed)
                currentBlue = other;
            else
                currentRed = other;
            int needRed = max(0, red[i] - currentRed - redCards[mask]);
            int needBlue = max(0, blue[i] - currentBlue - blueCards[mask]);
            int moves = max(needRed, needBlue);
            int newRed = currentRed + moves - max(0, red[i] - redCards[mask]);
            int newBlue = currentBlue + moves - max(0, blue[i] - blueCards[mask]);
            if (!newRed)
                answer = min(answer, moves + Solve(mask | (1 << i), 1, newBlue));
            else
                answer = min(answer, moves + Solve(mask | (1 << i), 0, newRed));
        }
    dp[mask][noRed][other] = answer;
    return answer;
}

int main() {
    cin >> n;
    int redOffset = 0, blueOffset = 0;
    for (int i = 0; i < n; i++) {
        cin >> color[i] >> red[i] >> blue[i];
        redOffset += max(red[i] - n, 0);
        blueOffset += max(blue[i] - n, 0);
        red[i] = min(red[i], n);
        blue[i] = min(blue[i], n);
    }
    Precompute();
    memset(dp, -1, sizeof(dp));
    int answer;
    if (redOffset < blueOffset)
        answer = Solve(0, 0, blueOffset - redOffset);
    else
        answer = Solve(0, 1, redOffset - blueOffset);
    answer = answer + n + max(blueOffset, redOffset);
    cout << answer << "\n";
    return 0;
}