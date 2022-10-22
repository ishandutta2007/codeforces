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
typedef pair<int,int> P;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int a[maxn], b[maxn];
bool check[maxn];

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1;i <= m; ++i) scanf("%d", &b[i]);
        memset(check, 0, sizeof(check));
        int st = 1;
        LL ans = 0;
        for(int i = 1;i <= m; ++i) {
            ans++;
            if(check[b[i]]) continue;
            else {
                while(a[st] != b[i]) check[a[st++]] = 1;
                ans += (st - i) * 2;
                st++;
            }
        }
        cout << ans << endl;
    }
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}