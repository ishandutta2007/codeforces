#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,tot;bool vis[MAXN];int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main(){cin>>N;int x=1;For(i,1,N-1)if(GCD(i,N)==1)tot++,vis[i]=1,x=1ll*x*i%N;if(x!=1)tot--,vis[x]=0;cout<<tot<<endl;For(i,1,N-1)if(vis[i])cout<<i<<' ';return 0;}