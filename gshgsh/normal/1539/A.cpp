#include<iostream>
#include<cstdio>
using namespace std;
int T,N,x,y;
int main(){cin>>T;while(T--){cin>>N>>x>>y;if(y/x>=N-1)cout<<1ll*N*(N-1)/2<<endl;else cout<<1ll*(y/x)*(y/x+1)/2+1ll*(y/x)*(N-1-y/x)<<endl;}return 0;}