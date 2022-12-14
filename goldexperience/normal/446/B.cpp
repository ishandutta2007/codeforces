#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

priority_queue<LL> Q;
const int maxn = 2000, maxm = 1200000;
int n, m, k, p;
int c[maxn][maxn];
int row[maxn], col[maxn];
LL frow[maxm], fcol[maxm];


int main(){
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            scanf("%d", &c[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i){
        row[i] = 0;
        for (int j = 1; j <= m; ++j)
            row[i] += c[i][j];
    }
    for (int j = 1; j <= m; ++j){
        col[j] = 0;
        for (int i = 1; i <= n; ++i)
            col[j] += c[i][j];
    }

    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; ++i)
        Q.push(row[i]);
    frow[0] = 0;
    fcol[0] = 0;
    for (int i = 1; i <= k; ++i){
        LL tmp = Q.top();
        frow[i] = frow[i - 1] + tmp;
        Q.pop();
        Q.push(tmp - (LL)p * m);
    }

    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= m; ++i)
        Q.push(col[i]);
    for (int i = 1; i <= k; ++i){
        LL tmp = Q.top();
        fcol[i] = fcol[i - 1] + tmp;
        Q.pop();
        Q.push(tmp - (LL)p * n);
    }

    LL ans = frow[k];
    for (int i = 0; i < k; ++i){
        LL tmp = frow[i] + fcol[k - i] - (LL)(k - i) * (LL)i * (LL)p;
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}