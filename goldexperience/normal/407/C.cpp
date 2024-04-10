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

const int mo = 1000000007, maxn = 101000;
LL C[500][500];
LL delta[500], tt[500], fac[maxn + 10], ny[maxn + 10];
int a[maxn];
int n, m;

struct Node{
    int l, r, k;
    bool operator < (const Node &u)const{
        return l < u.l;
    }
}c[maxn];

struct comp{
    bool operator ()(const Node &u, const Node &v)const{
        return u.r > v.r;
    }
};

priority_queue<Node, vector<Node>, comp > Q;

LL power(LL ret, int n){
    LL ans = 1;
    while (n){
        if (n & 1) ans = ans * ret % mo;
        ret = ret * ret % mo;
        n >>= 1;
    }
    return ans;
}

int main(){
    for (int i = 0; i <= 200; ++i)
        C[i][0] = 1;
    for (int i = 1; i <= 200; ++i)
        for (int j = 1; j <= 200; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
    fac[1] = 1;
    fac[0] = 1;
    ny[0] = 1;
    ny[1] = 1;
    for (int i = 2; i <= maxn; ++i){
        fac[i] = fac[i - 1] * (LL)i % mo;
        ny[i] = power(fac[i], mo - 2);
    }

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &c[i].l, &c[i].r, &c[i].k);
    sort(c, c + m);
    int now = 0;
    memset(delta, 0, sizeof(delta));
    for (int i = 1; i <= n; ++i){
        LL ans = a[i];
        while(!Q.empty() && Q.top().r < i){
            int N = Q.top().k + Q.top().r - Q.top().l; 
            for (int j = 0; j <= Q.top().k; ++j){
                int M = Q.top().k - j;
                LL t = fac[N] * ny[M] % mo * ny[N - M] % mo;
                delta[j] = (delta[j] - t + mo) % mo;
            }
            Q.pop();
        }
        for (int j = 100; j >= 0; --j)
            tt[j] = (delta[j] + delta[j + 1]) % mo;
        for (int j = 0; j <= 100; ++j)
            delta[j] = tt[j];
        while (now < m && c[now].l <= i){
            for (int j = 0; j <= c[now].k; ++j)
                delta[j] = (delta[j] + C[c[now].k][j]) % mo;
            Q.push(c[now]);
            ++now;
        }
        ans = (ans + delta[0]) % mo;
        if (i != n) printf("%d ", (int)ans); else printf("%d\n", (int)ans);
    }
    return 0;
}