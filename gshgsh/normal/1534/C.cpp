#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define P 1000000007
#define MAXN 500001
int T,N,a[MAXN],b[MAXN],pos[MAXN],c[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int x){if(vis[x])return;vis[x]=1;dfs(c[x]);}
int main()
{
    T=get();
    while(T--)
    {
        N=get();For(i,1,N)a[i]=get(),pos[a[i]]=i;For(i,1,N)b[i]=get();For(i,1,N)c[i]=b[pos[i]],vis[i]=0;
        int ans=1;For(i,1,N)if(!vis[i])dfs(i),ans=ans*2ll%P;cout<<ans<<endl;
    }
    return 0;
}