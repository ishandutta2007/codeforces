#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 200001
int T,N,M,a[MAXN],pos[MAXN],b[MAXN],vis[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get(),M=get();int ans=1;For(i,1,N)pos[a[i]=get()]=i,vis[i]=1;For(i,1,M)vis[pos[b[i]=get()]]=0;For(i,1,M)ans=1ll*ans*((pos[b[i]]>1&&vis[pos[b[i]]-1])+(pos[b[i]]<N&&vis[pos[b[i]]+1]))%P,vis[pos[b[i]]]=1;cout<<ans<<endl;}return 0;}