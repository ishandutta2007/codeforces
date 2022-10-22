#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,x[MAXN],y[MAXN];
int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cin>>x[i]>>y[i];sort(x+1,x+N+1);sort(y+1,y+N+1);cout<<1ll*(x[N/2+1]-x[N+1>>1]+1)*(y[N/2+1]-y[N+1>>1]+1)<<endl;}return 0;}