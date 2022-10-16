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
const int MOD = 1000000007;

int factorial[1 + MAXN], inverse[1 + MAXN], divide[1 + MAXN], cayley[1 + MAXN];
int n, dp[1 + MAXN][1 + MAXN][1 + MAXN], temp[1 + MAXN][1 + MAXN], sum[1 + MAXN][1 + MAXN], weight[1 + MAXN];
int answer[1 + MAXN];
vector<int> g[1 + MAXN];

void Add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

void Subtract(int &x, int y) {
    x -= y;
    if (x < 0)
        x += MOD;
}

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void Precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
        divide[i] = RaiseToPower(i, MOD - 2);
    }
    inverse[n] = RaiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
    cayley[0] = 0;
    cayley[1] = 1;
    for (int i = 2; i <= n; i++)
        cayley[i] = RaiseToPower(n, i - 2);
}

int Combinations(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

void DFS(int node, int father) {
    weight[node] = 1;
    dp[node][0][1] = 1;
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            for (int i = 0; i < weight[node]; i++)
                for (int j = 1; j <= weight[node]; j++)
                    temp[i][j] = 0;
            for (int i = weight[node] - 1; i >= 0; i--)
                for (int j = weight[node]; j >= 1; j--)
                    for (int a = min(n - 1 - i, weight[son] - 1); a >= 0; a--) {
                        Add(temp[i + a][j], 1LL * dp[node][i][j] * sum[son][a] % MOD);
                        if (i + a + 1 <= n - 1)
                            for (int b = min(n - j, weight[son]); b >= 1; b--)
                                Add(temp[i + a + 1][j + b], 1LL * dp[node][i][j] * dp[son][a][b] % MOD * divide[b] % MOD);
                    }
            weight[node] += weight[son];
            for (int i = 0; i < weight[node]; i++)
                for (int j = 1; j <= weight[node]; j++) {
                    dp[node][i][j] = temp[i][j];
                    temp[i][j] = 0;
                }
        }
    for (int i = 0; i < weight[node]; i++)
        for (int j = 1; j <= weight[node]; j++) {
            dp[node][i][j] = (1LL * dp[node][i][j] * j) % MOD;
            Add(sum[node][i], dp[node][i][j]);
        }
}

void Solve(int n) {
    answer[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        answer[i] = (1LL * sum[1][i] * cayley[n - i]) % MOD;
        for (int j = i + 1; j < n; j++)
            Subtract(answer[i], 1LL * answer[j] * Combinations(j, i) % MOD);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    Precompute(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    Solve(n);
    return 0;
}