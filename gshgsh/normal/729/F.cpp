#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 10000007
#define MAXN 40000000
int N,a[10000],s[10000],head[P],cnt,val[MAXN],f[MAXN],nxt[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int get(ll x){int a=x/P,b=x%P;for(int i=head[b];i;i=nxt[i])if(val[i]==a)return f[i];return 2.1e9;}
void insert(ll x,int v){val[++cnt]=x/P,f[cnt]=v,nxt[cnt]=head[x%P],head[x%P]=cnt;}
ll getv(int l,int r,int k,int a){return ((1ll*l*(N+1)+r)*(N+1)+k)*2+a;}int sum(int l,int r){return s[r]-s[l-1];}
int dfs(int l,int r,int k,int a)
{
	if(r-l+1<k)return 0;if(r-l+1==k)return sum(l,r)*(a==0?1:-1);
	ll x=getv(l,r,k,a);int tmp=get(x);if(tmp<2e9)return tmp;
	if(a==0){int ans=max(dfs(l+k,r,k,1)+sum(l,l+k-1),dfs(l+k+1,r,k+1,1)+sum(l,l+k));insert(x,ans);return ans;}
	int ans=min(dfs(l,r-k,k,0)-sum(r-k+1,r),dfs(l,r-k-1,k+1,0)-sum(r-k,r));insert(x,ans);return ans;
}
int main(){N=get();For(i,1,N)a[i]=get(),s[i]=s[i-1]+a[i];cout<<dfs(1,N,1,0)<<'\n';return 0;}