#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N;int ans=N;For(i,1,N){int x;cin>>x;ans-=x==2;}cout<<ans<<endl;}return 0;}