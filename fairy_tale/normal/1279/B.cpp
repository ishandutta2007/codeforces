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

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn];
LL s[maxn];

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    int t, n, ss,best_id, val;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &ss);
        for(int i = 1;i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1;i <= n; ++i) s[i]= s[i - 1] + a[i];
        if(s[n] <= ss) {
            puts("0");
            continue;
        }
        s[n + 1] = 0;
        best_id = 0;
        val = 0;
        for(int i = 1;i <= n; ++i) {
            if(s[i - 1] > ss) break;
            LL d = ss + a[i];
            int k = upper_bound(s + i, s + n + 1, d) - s;
            if(k > val) {
                val = k;
                best_id = i;
            }
        }
        printf("%d\n", best_id);
    }
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}