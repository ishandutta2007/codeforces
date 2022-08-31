#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
ll a[maxn],b[maxn],c[maxn],d[maxn],p[maxn],q[maxn],n,ans,r,u,v,_u,_v;
ll A,B,C,D,E,F;
map<pi,int> f;
bool g[1111111];
bool cc(ll x,ll y,ll z){
    if (y<x&&y<z) return false;
    if (y>x&&y>z) return false;
    return true;
}
int main(){
    cin >> n;
    int s=0; for (int i=1;i<=1000;i++) s+=i,g[s]=true;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        r=__gcd(abs(a[i]-c[i]),abs(d[i]-b[i]));
        ans+=r+1; p[i]=(c[i]-a[i])/r; q[i]=(d[i]-b[i])/r;
    }
    //cout<<ans<<endl;
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++){
        if (p[i]*q[j]==p[j]*q[i]) continue;
        A=p[i]; B=p[j]; C=a[j]-a[i];
        D=q[i]; E=q[j]; F=b[j]-b[i];
        ll m=A*E-B*D;
        if ((F*B-C*E)%m) continue;
        if ((D*C-A*F)%m) continue;
        u=-(F*B-C*E)/m;
        v=(D*C-A*F)/m;
        //cout<<u<<' '<<v<<endl;
        _u=u*p[i]+a[i];
        _v=u*q[i]+b[i];
        u=_u; v=_v;
        //cout<<u<<' '<<v<<endl;
        if (!cc(a[i],u,c[i])||!cc(b[i],v,d[i])||!cc(a[j],u,c[j])||!cc(b[j],v,d[j]))
            continue;
        f[(pi){u,v}]++;
        if (g[f[(pi){u,v}]]) ans--;
    }
    cout << ans << endl;
}