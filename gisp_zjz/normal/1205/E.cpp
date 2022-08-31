#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const ll M=1000000007;
const int maxn=211111;
ll n,k,p[maxn],ans,cnt[maxn],phi[maxn],mu[maxn],f[maxn];
vector <int> h[maxn];
void cc(int x,int y){
    for (auto v:h[x]){
        int r=y/v;
        for (auto vv:h[v]) cnt[vv]+=mu[v/vv]*r;
    }
}
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
int main(){
    cin >> n >> k;
    for (int i=1;i<maxn;i++) phi[i]=i; mu[1]=1;
    for (int i=1;i<maxn;i++)
        for (int j=2;j*i<maxn;j++) phi[i*j]-=phi[i],mu[i*j]-=mu[i];
    for (int i=1;i<maxn;i++)
        for (int j=1;j*i<maxn;j++)
            h[i*j].pb(i);
    for (int i=1;i<n;i++) cc(i,n-i);
    for (int i=n+1;i<=n*2-2;i++){
        int l,r;
        l=i-n; r=n-1;
        for (auto v:h[i]){
            int t=r/v-l/v;
            for (auto vv:h[v]) f[vv]+=mu[v/vv]*t;
        }
        for (auto v:h[i]){
            cnt[max(v,i-(int)n)]+=f[v];
            f[v]=0;
        }
    }
    for (int i=0;i<maxn;i++) cnt[i]%=M;
    for (int i=0;i<maxn;i++) (ans+=pow_(k,i)*cnt[i])%=M;
    ll inv=pow_(k,M-2);
    ans=ans*pow_(inv,n)%M;
    cout << ans << endl;
    return 0;
}