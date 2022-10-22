#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int T,N,a[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>a[i];For(i,1,N)if(a[i]&1)cout<<a[i]<<' ';For(i,1,N)if((a[i]&1)^1)cout<<a[i]<<' ';cout<<endl;}return 0;}