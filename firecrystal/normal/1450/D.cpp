#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 3e5 + 5, L = 19;

int n, a[N], cnt[N], ans[N], f[N][L], k[N];

void ST_prework(){
    k[0] = -1;
    for(int i=1;i<=n;i++) k[i] = k[i >> 1] + 1; 
    int t = (log(n)/log(2)) + 1;
    for(int j=1;j<t;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    } 
}

int inline get(int l, int r){
    if (l > r) return 2e9;
    int K = k[r - l + 1];
    return min(f[l][K], f[r - (1 << K) + 1][K]);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) cnt[i] = 0, ans[i] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", a + i), cnt[a[i]]++, f[i][0] = a[i];
        ST_prework();
        ans[1] = 1;
        for (int i = 1; i <= n; i++)
            if (cnt[i] != 1) { ans[1] = 0; }
        
        int l = 1, r = n;
        if (get(1, n) == 1) ans[n] = 1;

        for (int i = 1; i <= n; i++) {
            if (a[l] == i) l++;
            else if (a[r] == i) r--;
            else {
                if (get(l, r) == i) {
                    ans[n - i + 1] = 1;
                }
                break;
            }
            if (get(l, r) < i) break;
            ans[n - i + 1] = 1;
        }
        for (int i = 1; i <= n; i++) printf("%d", ans[i]);
        puts("");
    }   
    return 0;
}