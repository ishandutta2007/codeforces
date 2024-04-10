#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];ll f[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i];ll ans=0;FOR(i,N,1)ans=max(ans,f[i]=a[i]+(i+a[i]<=N?f[i+a[i]]:0));cout<<ans<<endl;}return 0;}