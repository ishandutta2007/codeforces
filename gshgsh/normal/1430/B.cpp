#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,K,a[MAXN];int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cin>>a[i];sort(a+1,a+N+1,greater<int>());ll ans=0;For(i,1,K+1)ans+=a[i];cout<<ans<<endl;}return 0;}