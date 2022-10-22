#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 10000001
int N,x,y;ll f[MAXN];
int main(){cin>>N>>x>>y;For(i,1,N)f[i]=min(f[i-1]+x,i&1?f[i+1>>1]+x+y:f[i>>1]+y);cout<<f[N]<<endl;return 0;}