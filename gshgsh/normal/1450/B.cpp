#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 101
int T,N,K,x[MAXN],y[MAXN];
int main(){cin>>T;while(T--){cin>>N>>K;int ans=-1;For(i,1,N)cin>>x[i]>>y[i];For(i,1,N){bool flag=1;For(j,1,N)if(abs(x[i]-x[j])+abs(y[i]-y[j])>K){flag=0;break;}if(flag){ans=1;break;}}cout<<ans<<endl;}return 0;}