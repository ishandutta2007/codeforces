#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

const int maxn = 1e6 + 5;
const int mod = 998244353;

ULL p[55];
ULL f[55];
int d[55], to[55], used[55];

void upd(ULL &x, ULL y, ULL w) {
    if((double)y * w > 2e18)
        x += 2e18;
    else
        x += y * w;
    if(x > 2e18)
        x = 2e18;
}

int ff(int x) {
    if(to[x] != x)
        to[x] = ff(to[x]);
    return to[x];
}

void solve2(int l, int r, ULL id) {
    //cout<<l<<" "<<r<<" "<<id<<endl;
    d[l] = r;
    memset(to, 0, sizeof(to));
    memset(used, 0, sizeof(used));
    for(int i = l; i <= r; ++i)
        to[i] = i;
    to[l] = r;
    used[r] = 1;
    for(int i= l + 1; i <= r; ++i) {
        if(i == r) {
            for(int j = l; j <= r; ++j) {
                if(!used[j]) {
                    d[i] = j;
                    return;
                }
            }
        }
        ULL w = p[max(r - i - 1, 0)];
        for(int j = l; j <= r; ++j) {
            if(!used[j] && ff(j) != i) {
                if(w < id)
                    id -= w;
                else {
                    to[i] = j;
                    d[i] = j;
                    used[j]= 1;
                    break;
                }
            }
        }
    }
}

void solve(int i, int n, ULL k) {
    if(i > n)
        return;
    for(int j = 0; j <= n - i; ++j) {
        ULL w = 0;
        upd(w, f[n - i - j], p[max(j - 1, 0)]);
        if(k < w) {
            ULL id = k / f[n - i - j] + 1;
            k %= f[n - i - j];
            solve2(i, i + j, id);
            solve(i + j + 1, n, k);
            return;
        } else
            k -= w;
    }
}

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    p[0] = 1;//max 20
    for(int i = 1; i <= 50; ++i)
        upd(p[i], p[i - 1], i);
    f[0] = 1;
    for(int i = 0; i < 50; ++i) {
        for(int j = 1; i + j <= 50; ++j) {
            upd(f[i + j], f[i], p[max(j - 2, 0)]);
        }
    }
    int t, n;
    LL k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%lld", &n, &k);
        if(f[n] < k) {
            puts("-1");
            continue;
        }
        solve(1, n, k - 1);
        for(int i = 1; i <= n; ++i)
            printf("%d ", d[i]);
        puts("");
    }
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}