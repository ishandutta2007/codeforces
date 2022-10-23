#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=1000000007;
const int inv2=(M+1)/2;
int kase=0;
int n,ans[maxn],s[maxn],f[maxn],g[maxn],p[maxn],q[maxn];
void solve(){
    scanf("%d",&n);
    s[n+1]=0; f[n]=2; s[n]=g[n]=1ll*f[n]*p[n]%M; 
    for (int i=n-1;i>=1;i--){
        g[i]=(s[i+1]-s[min(i*2,n+1)]+M)%M;
        f[i]=1ll*g[i]*q[i]%M;
        s[i]=(s[i+1]+g[i])%M;
    }
    for (int i=1;i<=n;i++){
        ans[i]=1ll*p[i-i/2]*f[i]%M;
        printf("%d\n",ans[i]);
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    p[0]=q[0]=1; for (int i=1;i<maxn;i++) p[i]=1ll*p[i-1]*inv2%M,q[i]=2*q[i-1]%M;
    int _; scanf("%d",&_);
    while (_--) solve();
}