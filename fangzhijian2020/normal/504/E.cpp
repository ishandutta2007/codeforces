#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=998244353,base=29;
int Hash1[300005],Hash2[300005],tmp[600010],*mi=tmp+300005;
vector<int>up[300005],down[300005];
int n,m,x,y,X,Y,h[300005],cnt;char c[300005];
struct edge{int to,next;}e[600005];
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
int f[300005][20],d[300005],len[300005],mx[300005],son[300005],top[300005],lg[300005];
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
void dfs1(int x,int prt){
	int i,y;f[x][0]=prt;mx[x]=d[x];
	for(i=1;i<20;++i)f[x][i]=f[f[x][i-1]][i-1];
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		d[y]=d[x]+1;
		Hash1[y]=(1ll*Hash1[x]*base%mod+int(c[y]-'a'+1))%mod;
		Hash2[y]=(1ll*Hash2[x]+1ll*int(c[y]-'a'+1)*mi[d[y]])%mod;
		dfs1(y,x);
		if(mx[y]>mx[x])son[x]=y,mx[x]=mx[y];		
	}
}
void dfs2(int x,int Top){
	int i,y;top[x]=Top;
	len[x]=mx[x]-d[Top]+1;
	if(son[x])dfs2(son[x],Top);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(y==f[x][0]||y==son[x])continue;
		dfs2(y,y);
	}
}
int find_k(int x,int k){
	if(!k)return x;if(d[x]<k)return 0;
	x=f[x][lg[k]];k^=(1<<lg[k]);if(!k)return x;
	if(d[x]-d[top[x]]==k)return top[x];
	if(d[x]-d[top[x]]>k)return down[top[x]][d[x]-d[top[x]]-k-1];
	return up[top[x]][k-d[x]+d[top[x]]-1];
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=19;~i;--i){
		if(d[x]-(1<<i)>=d[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;~i;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];y=f[y][i];
		}
	}
	return f[x][0];
}
int get_hash(int x,int y,int lca,int len){
	if(d[x]-d[lca]+1>=len)return (Hash1[x]-1ll*Hash1[find_k(x,len)]*mi[len]%mod+mod)%mod;len=len-d[x]+d[lca]-1;
	return ((Hash1[x]-1ll*Hash1[f[lca][0]]*mi[d[x]-d[lca]+1]%mod+mod)%mod+1ll*(Hash2[find_k(y,d[y]-d[lca]-len)]-Hash2[lca]+mod)%mod*mi[d[x]-(d[lca]<<1)]%mod)%mod;
}
int query(int x,int y,int X,int Y){
	int lca1=LCA(x,y),lca2=LCA(X,Y),l=1,r=0,mid;
	r=min(d[x]+d[y]-(d[lca1]<<1)+1,d[X]+d[Y]-(d[lca2]<<1)+1);
	while(l<=r){
		mid=(l+r)>>1;
		if(get_hash(x,y,lca1,mid)==get_hash(X,Y,lca2,mid))l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	scanf("%d%s",&n,c+1);mi[0]=1;
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		mi[i]=1ll*mi[i-1]*base%mod;
	}
	mi[-n+1]=ksm(mi[n-1],mod-2);
	for(int i=n-2;i>=1;--i){
		mi[-i]=1ll*mi[-i-1]*base%mod;
	}
	Hash1[1]=Hash2[1]=int(c[1]-'a'+1);dfs1(1,0);dfs2(1,1);
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i){
		if(i==top[i]){
			int k;
			k=0;x=i;while(k<len[i]&&x){x=f[x][0];up[i].push_back(x);++k;}
			k=0;x=i;while(k<len[i]){x=son[x];down[i].push_back(x);++k;}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&x,&y,&X,&Y);
		if(c[x]!=c[X]){puts("0");continue;}
		printf("%d\n",query(x,y,X,Y));
	}
	return 0;
}