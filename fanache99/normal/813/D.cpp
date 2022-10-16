#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAXN = 5000;
const int MOD = 7;
const int MAXVAL = 100000;

int v[1 + MAXN];
int dp[1 + MAXN][1 + MAXN];
int bestMod[MOD], bestValue[1 + MAXVAL + 1];

void Update(int &x, int y) {
    if (x < y)
        x = y;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    int answer = 0;
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i < MOD; i++)
            bestMod[i] = 0;
        for (int i = 1; i <= n; i++)
            bestValue[v[i]] = 0;
        for (int i = 1; i <= j; i++) {
            Update(bestMod[v[i] % 7], dp[i][j]);
            Update(bestValue[v[i]], dp[i][j]);
        }
        for (int i = j + 1; i <= n; i++) {
            Update(dp[i][j], bestMod[v[i] % 7] + 1);
            Update(dp[i][j], bestValue[v[i] - 1] + 1);
            Update(dp[i][j], bestValue[v[i] + 1] + 1);
            Update(dp[i][j], dp[0][j] + 1);
            Update(bestMod[v[i] % 7], dp[i][j]);
            Update(bestValue[v[i]], dp[i][j]);
            Update(answer, dp[i][j]);
            dp[j][i] = dp[i][j];
        }
    }
    printf("%d\n", answer);
    return 0;
}