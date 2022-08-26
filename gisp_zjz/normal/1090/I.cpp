#include<bits/stdc++.h>
#define maxn 10000005

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n,T;
ll l,r,a[maxn],p[maxn],q[maxn],ans;
const ull M=4294967296ull;
ull x,y,z,b[maxn];

int main(){
    cin >> T;
    while (T--){
        cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2]; ans=5e18;
        for (int i=3;i<=n;i++) b[i]=(b[i-2]*x+b[i-1]*y+z)%M;
        for (int i=1;i<=n;i++) a[i]=b[i]%(r-l+1)+l;
        p[1]=a[1]; for (int i=2;i<=n;i++) p[i]=min(p[i-1],a[i]);
        q[n]=a[n]; for (int i=n-1;i;i--) q[i]=max(q[i+1],a[i]);
        for (int i=1;i<n;i++) if (q[i+1]>a[i]) ans=min(ans,a[i]*q[i+1]);
        for (int i=n;i>1;i--) if (p[i-1]<a[i]) ans=min(ans,a[i]*p[i-1]);
        if (ans>4.5e18) puts("IMPOSSIBLE"); else cout << ans << endl;
    }
    return 0;
}