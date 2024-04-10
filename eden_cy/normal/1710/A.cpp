#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
const int Mod=998244353;
ll Fast(ll x,int b) {
    ll t=1;
    for(; b; b>>=1,x=x*x%Mod) {
        if(b&1) t=t*x%Mod;
    }
    return t;
}
const int N=1e5+50;
int a[N],b[N];
void solve() {
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    FOR(i,1,K) scanf("%d",&a[i]);
    {
        FOR(i,1,K) b[i]=a[i]/n;
        sort(b+1,b+K+1);
        ll s=0,c=0;
        DOR(i,K,1) {
            if(b[i]>=2) {
                s+=2;c+=b[i]-2;
            }
            if(s<=m && m<=s+c) {
                puts("YES");
                return ;
            }
        }
    }
    {

        FOR(i,1,K) b[i]=a[i]/m;
        sort(b+1,b+K+1);
        ll s=0,c=0;
        DOR(i,K,1) {
            if(b[i]>=2) {
                s+=2;c+=b[i]-2;
            }
            if(s<=n && n<=s+c) {
                puts("YES");
                return ;
            }
        }
    }
    puts("NO");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}