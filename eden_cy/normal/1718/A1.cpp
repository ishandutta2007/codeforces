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
const int N=1e6+50;
int a[N];
map<int,int> pre;
int f[N];
void solve() {
    pre.clear();
    int n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int s=0;
    pre[0]=0;
    FOR(i,1,n) {
        s^=a[i];
        if(pre.count(s)) {
            f[i]=f[pre[s]]+1;
        } else f[i]=0;
        pre[s]=i;
        f[i]=max(f[i],f[i-1]);
    }
    printf("%d\n",n-f[n]);
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}