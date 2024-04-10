#include<bits/stdc++.h>
#define maxn 234560

using namespace std;
typedef long long ll;
const ll inf=1e10;
ll n,m,S,a[maxn],b[maxn],s[maxn],p[maxn],q[maxn],ans;

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    cin >> S; //ans=inf;
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++){
        p[i]=inf;
        for (int j=0;j+i<=n;j++)
            p[i]=min(p[i],s[i+j]-s[j]);
    }
    for (int i=1;i<=m;i++) s[i]=s[i-1]+b[i];
    for (int i=1;i<=m;i++){
        q[i]=inf;
        for (int j=0;j+i<=m;j++)
            q[i]=min(q[i],s[i+j]-s[j]);
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (p[i]*q[j]<=S) ans=max(ans,(ll)i*j);
    cout << ans << endl;
    return 0;
}