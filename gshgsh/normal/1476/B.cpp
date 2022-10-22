#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,K;ll a[MAXN];int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cin>>a[i];ll sum=a[1],ans=0;For(i,2,N)ans+=max((a[i]*100+K-1)/K-sum,0ll),sum+=max((a[i]*100+K-1)/K-sum,0ll),sum+=a[i];cout<<ans<<endl;}return 0;}