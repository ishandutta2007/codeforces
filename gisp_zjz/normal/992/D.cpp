#include<bits/stdc++.h>
#define maxn 502030

using namespace std;
typedef long long ll;
const ll inf = 2e13;
ll a[maxn],s[maxn],p[maxn],n,k,ans,d,m,b[maxn],w,r,x,y;

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++) if (a[i]>1){
        b[++m]=a[i];
        p[m]=i;
    }
    p[m+1]=n+1;
    for (int i=1;i<=m;i++){
        d=b[i]; int j=i;
        while (true){
            w=s[p[j]]-s[p[i]-1];
            if (d%k==0){
                r=d/k-w;
                //cout << i << ' ' << j <<' ' << r << endl;
                x=p[j+1]-p[j]-1;
                y=p[i]-p[i-1]-1;
                //cout << x << ' ' << y << ' ' << r << '!' << endl;
                if (r>=0&&r<=x+y) ans+=min(min(r,x+y-r),min(x,y))+1;
            }
            if (j==m) break;
            j++; if (inf/b[j]<d) break;
            d=d*b[j];
        }
    }
    if (k==1) ans+=(n-m);
    cout << ans << endl;
}