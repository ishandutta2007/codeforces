#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=1e9+7;
ll Fast(ll x,int b) {
    ll t=1;
    for(; b; b>>=1,x=x*x%Mod) {
        if(b&1) t=t*x%Mod;
    }
    return t;
}
const int N=1005;
int a[N];
ll f[N],sum[N];
bool res;
int n;
void dfs(int p,int las) {
    if(p<0) {res=1;return ;}
    FOR(i,1,n) if(las!=i && a[i]>=f[p]) {
        a[i]-=f[p];
        dfs(p-1,i);
        if(res) return ;
        a[i]+=f[p];
    }
}
void solve() {
    scanf("%d",&n);
    ll s=0;
    FOR(i,1,n) scanf("%d",&a[i]),s+=a[i];
    int m=100;
    f[0]=f[1]=1;
    FOR(i,2,m) f[i]=f[i-2]+f[i-1];
    sum[0]=f[0];
    FOR(i,1,m) sum[i]=sum[i-1]+f[i];
    int K=0;
    FOR(i,0,m) {
        if(sum[i]==s) {
            K=i;
            break;
        }
        if(sum[i]>s) {
            puts("NO");
            return ;
        }
    }
    res=0;
    dfs(K,0);
    puts(res?"YES":"NO");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}