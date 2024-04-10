#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2005;

struct Enode{
    int y, next;
} e[N * N];
char s[N][N];
int head[N * N], tot, in[N * N], v[N * N], dp[N * N], ans;
int n, m, cnt;
vector<int> vec;
int G(int x, int y){return x * m + y;}
void Add(int x, int y){
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot; in[y]++; cnt++;
}

bool Dfs(int x){
    v[x] = 1;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (v[e[p].y] == 1) return 1;
    else if (!v[e[p].y]){
        if (Dfs(e[p].y)) return 1;
    }
    v[x] = 2;
    return 0;
}
int DP(int x){
    if (dp[x] != -1) return dp[x];
    int ret = 0;
    for (int p = head[x]; p != -1; p = e[p].next){
        int t = DP(e[p].y);
        if (s[x / m][x % m] == '#' && t + 1 == ret) ans = max(ans, ret * 2);
        ret = max(ret, t + 1);
    }
    return dp[x] = ret;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (s[i][j] == '^') Add(G(i, j), G(i - 1, j));
    else if (s[i][j] == 'v') Add(G(i, j), G(i + 1, j));
    else if (s[i][j] == '<') Add(G(i, j), G(i, j - 1));
    else if (s[i][j] == '>') Add(G(i, j), G(i, j + 1));

    if (cnt < 2){
        puts("0");
        return 0;
    }
    n = n * m;
    for (int i = 0; i < n; i++){
        if (Dfs(i)){
            puts("-1");
            return 0;
        }
    }

    ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        DP(i);
    for (int i = 0; i < n; i++)
    if (s[i / m][i % m] == '#'){
        vec.push_back(dp[i]);
        ans = max(ans, dp[i] + dp[i] - 1);
    }
    sort(vec.begin(), vec.end());
    int n = vec.size();
    printf("%d\n", max(ans, vec[n - 1] + vec[n - 2]));
}