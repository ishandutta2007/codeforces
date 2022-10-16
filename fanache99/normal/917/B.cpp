#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 100;
const int SIGMA = 26;

vector<pair<int, int> > g[1 + MAXN];
char dp[1 + MAXN][1 + MAXN][SIGMA];

void DP(int a, int b, char c) {
    if (dp[a][b][c] != -1)
        return;
    dp[a][b][c] = 0;
    for (auto &it : g[a])
        if (it.second >= c) {
            DP(b, it.first, it.second);
            if (dp[b][it.first][it.second] == 0) {
                dp[a][b][c] = 1;
                break;
            }
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        char c;
        scanf("%d%d %c", &a, &b, &c);
        g[a].push_back(make_pair(b, c - 'a'));
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int c = 0; c < SIGMA; c++)
                DP(i, j, c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dp[i][j][0])
                printf("A");
            else
                printf("B");
        printf("\n");
    }
    return 0;
}