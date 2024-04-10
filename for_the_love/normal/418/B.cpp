#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;
typedef pair<string, string> PS;
const DB eps = 1e-6;
const int N = 1e3 +7;
const int MOD = 1e9 + 7;
const LL INF = 3e18 + 7;

int n, m, x[100], k[100], p[100], cnt[100], b[100];
LL B, dp[1 << 20];

bool cmp(int i, int j){return k[i] < k[j];}



int main(){
    //freopen("in.txt", "r", stdin);
    int tmp;
    cin >> n >> m >> B;
    int tot = 0;
    for (int i = 0; i < n; i++){
        scanf("%d%d%d", &x[i], &k[i], &cnt[i]);
        for (int j = 0; j < cnt[i]; j++){
            scanf("%d", &tmp);
            p[i] |= 1 << (tmp - 1);

        }
        tot |= p[i];
        b[i] = i;
    }
    sort(b, b + n, cmp);

    if (tot != (1 << m) - 1){
        puts("-1");
        return 0;
    }
    for (int i = 0; i <= tot; i++) dp[i] = INF;
    LL ans = INF;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    for (int j = tot; j >= 0; j--)
    if ((j | p[b[i]]) == tot) ans = min(ans, dp[j] + k[b[i]] * B + x[b[i]]);
    else dp[j | p[b[i]]] = min(dp[j | p[b[i]]], dp[j] + x[b[i]]);

    cout << ans << endl;
}