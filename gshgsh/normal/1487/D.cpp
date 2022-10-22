#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;
int main(){cin>>T;while(T--){cin>>N;int ans=0;For(i,2,N)if(i&1)if(i*i<=N*2-1)ans++;else break;cout<<ans<<endl;}return 0;}