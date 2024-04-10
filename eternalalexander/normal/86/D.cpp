#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

long long arr[200005], size, vis[2000005];
long long answ[200005];
struct query {
    int l, r, b, p;
}qrys[200005];
int cmp(query a, query b) {
    if (a.b!=b.b) return a.b<b.b;
    return a.r<b.r;
}int n, q;

int main() {
    std::memset(vis, 0, sizeof(vis));
    scanf("%d %d", &n, &q);
    for (int i=1;i<=n;++i) scanf("%d", &arr[i]);
    size=(int)std::sqrt(n);
    //printf("%d",size);
    for (int i=1;i<=q;++i) {
        scanf("%d %d", &qrys[i].l, &qrys[i].r);
        qrys[i].b=(qrys[i].l-1)/size+1;qrys[i].p=i;
    }std::sort(qrys+1, qrys+q+1, cmp);
    int l=0,r=0; long long ans=0;
    for (int i=1;i<=q;++i) {
       // return 0;
       //printf("query %d: %d %d\n", qrys[i].p, qrys[i].l, qrys[i].r);
        while (l<qrys[i].l) {
            ans-=(vis[arr[l]]*2-1)*arr[l];
            vis[arr[l]]--; l++;
        }while (l>qrys[i].l) {
            l--;
            vis[arr[l]]++; ans+=(vis[arr[l]]*2-1)*arr[l];
           // ans+=(vis[arr[l]]*2-1)*arr[l];
        }while (r>qrys[i].r) {
            ans-=(vis[arr[r]]*2-1)*arr[r];
            vis[arr[r]]--; r--;
        }while (r<qrys[i].r) {
            r++;
            vis[arr[r]]++; ans+=(vis[arr[r]]*2-1)*arr[r];
            //ans+=(vis[arr[r]]*2-1)*arr[r];
        }answ[qrys[i].p]=ans;
       // printf("%d>", ans);
    }for (int i=1;i<=q;++i) printf("%lld\n", answ[i]);
}