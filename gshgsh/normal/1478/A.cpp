#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],cnt[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cnt[i]=0;For(i,1,N)cin>>a[i],cnt[a[i]]++;int ans=0;For(i,1,N)ans=max(ans,cnt[i]);cout<<ans<<endl;}return 0;}