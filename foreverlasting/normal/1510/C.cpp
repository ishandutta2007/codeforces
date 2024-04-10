#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define res register int
#define gc getchar
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
inline void swap(res &x,res &y){
	x^=y^=x^=y;
}
int n,m;
int dfn[N],low[N],idx;
int f[N],fa[N];
#define Pair pair<int,int>
#define mp make_pair
#define pb push_back
vector<Pair> ans;
vector<int> G[N];
void tarjan(res x,res fax){
	dfn[x]=low[x]=++idx,fa[x]=fax;
	res now=0;
	for(auto tox:G[x]){
		if(tox==fax)continue;
		if(!dfn[tox]){
			tarjan(tox,x);
			low[x]=min(low[x],low[tox]);
			if(!f[tox]||f[tox]==tox)continue;
//			if(now)printf("%d %d %d %d\n",now,f[tox],x,tox);
			if(now)ans.pb(mp(now,f[tox])),now=0;
			else now=f[tox];
//			printf("%d %d %d %d\n",now,tox,f[tox],x);
		}
		else {
			low[x]=min(low[x],dfn[tox]);
		}
	}
	if(x==1||dfn[x]>low[x]){
		for(auto tox:G[x]){
			if(fa[tox]==x&&f[tox]==tox)
			{
				if(now)ans.pb(mp(now,tox)),now=0;
				else now=tox;
			}
		}
//		printf("%d %d\n",now,x);
		if(now&&fa[now]!=x)ans.pb(mp(now,x));
	}
	else {
		f[x]=now;
		res other=0;
		for(auto tox:G[x]){
			if(fa[tox]!=x||f[tox]!=tox)continue;
			if(!f[x])f[x]=tox;
			else if(!other)other=tox;
			else {
				ans.pb(mp(f[x],other)),other=0;
				f[x]=tox;
			}
		}
		if(!f[x])f[x]=x;
	}
}
#define fi first
#define se second
int main(){
	while(233){
		n=read(),m=read();
		if(n==0&&m==0)return 0;
		for(res i=1;i<=n;i++)vector<int>().swap(G[i]),fa[i]=f[i]=dfn[i]=low[i]=0;
		vector<Pair>().swap(ans);
		idx=0;
		for(res i=1;i<=m;i++){
			res t=read()-1,pre=read();
			while(t--){
				res u=read();
				G[u].pb(pre),G[pre].pb(u),pre=u;
			}
		}
		tarjan(1,0);
		printf("%d\n",int(ans.size()));
		for(auto x:ans)printf("%d %d\n",x.fi,x.se);
	}
	return 0;
}