#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,a[MAXN],b[MAXN],ans;bool vis[MAXN];
int main(){cin>>T;while(T--){cin>>N>>M;ans=0;For(i,1,100)vis[i]=0;For(i,1,N)cin>>a[i],vis[a[i]]=1;For(i,1,M)cin>>b[i],ans+=vis[b[i]];cout<<ans<<endl;}return 0;}