#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1000001
int T,N,a[MAXN],tot,sta[MAXN];bool vis[MAXN];vector<int>ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
bool dfs(int x){if(vis[x]){ans.push_back(x);while(sta[tot]!=x)ans.push_back(sta[tot--]);return 1;}sta[++tot]=x,vis[x]=1;return dfs(x-a[x]);}
int main(){T=get();while(T--){N=get(),tot=0;For(i,1,N)a[i]=get(),vis[i]=0;For(i,1,N)if(dfs(i)){put(ans.size()),putchar('\n');for(auto j:ans)put(j),putchar(' ');putchar('\n');ans.clear();break;}}return 0;}