#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e4 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


char s[1111][15][15];
int d[1111][1111], from[1111], v[1111], f[1111];
int n, m, K, w;


vector <PI> ans;
int dis(int p, int q){
    int ret = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (s[p][i][j] != s[q][i][j]) ret++;
    return ret;
}

int main(){
    scanf("%d%d%d%d", &n, &m, &K, &w);
    for (int i = 1; i <= K; i++)
    for (int j = 1; j <= n; j++)
        scanf("%s", s[i][j] + 1);
    for (int i = 1; i <= K; i++)
    for (int j = i + 1; j <= K; j++)
        d[i][j] = d[j][i] = dis(i, j) * w;
    for (int i = 1; i <= K; i++) d[0][i] = d[i][0] = n * m;

    memset(v, 0, sizeof(v));
    memset(f, 0x7f, sizeof(f));
    f[0] = 0;
    int tot = 0;
    for (int i = 0; i <= K; i++){
        int mn = INF, node = i;
        for (int j = 0; j <= K; j++)
        if (!v[j] && f[j] < mn){
            mn = f[j];
            node = j;
        }
        v[node] = 1;
        tot += mn;
        if (i) ans.PB(MP(node, from[node]));
        for (int j = 0; j <= K; j++)
        if (!v[j] && d[node][j] < f[j]){
            f[j] = d[node][j];
            from[j] = node;
        }
    }

    printf("%d\n", tot);
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);

}