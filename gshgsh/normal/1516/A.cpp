#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,K,a[MAXN];int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cin>>a[i];For(i,1,N-1){int x=min(a[i],K);a[i]-=x,K-=x,a[N]+=x;}For(i,1,N)cout<<a[i]<<' ';cout<<endl;}return 0;}