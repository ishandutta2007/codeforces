#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 200005
#define inf 0x3f3f3f3f
int n,m;
set<int>vis,ns;
set<int>e[maxn];

int id[maxn],cnt,sz[maxn],mn[maxn],now[maxn];

void dfs(int u)
{
	vector<int>v;sz[cnt]++;
	vis.erase(u);id[u]=cnt;ns.clear();
	for(auto it=vis.begin();it!=vis.end();++it)
		if(!e[u].count((*it)))v.push_back((*it));
		else ns.insert((*it));
	vis=ns;
	for(int i=0;i<v.size();++i)dfs(v[i]);
}

int fa[maxn],res;
inline int getf(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
int uu[maxn],vv[maxn],ww[maxn],P[maxn];
bool cmp(int x,int y){
	return ww[x]<ww[y];
}

int fa2[maxn];
inline int getf2(int x){
	while(x!=fa2[x])x=fa2[x]=fa2[fa2[x]];
	return x;
}

signed main()
{
	n=read(),m=read();
	int X=0;
	For(i,1,m){
		int u=read(),v=read(),w=read();
		uu[i]=u,vv[i]=v,ww[i]=w;
		e[u].insert(v),e[v].insert(u);
		X^=w;
	}
	For(i,1,n)vis.insert(i);
	For(i,1,n)if(vis.count(i))cnt++,fa[cnt]=cnt,dfs(i);
	For(i,1,m){
		P[i]=i;
	}
	sort(P+1,P+m+1,cmp);
	int minn=2147483647;
	For(i,1,n)fa2[i]=i;
	For(i,1,m){
		int p=P[i];
		int u=id[uu[p]],v=id[vv[p]];
		if(getf(u)==getf(v))continue;
//		cout<<"u,v,w "<<u<<' '<<v<<" "<<ww[p]<<endl;
		fa2[getf2(uu[p])]=getf2(vv[p]);
		fa[getf(u)]=getf(v);
		res+=ww[p];
	}
	For(i,1,m){
		if(getf2(uu[i])!=getf2(vv[i]))
			minn=min(minn,ww[i]);
	}
	For(i,1,cnt)mn[i]=2147483647,now[i]=sz[i]*(sz[i]-1)/2;
	For(i,1,m){
		if(id[uu[i]]==id[vv[i]]){
			mn[id[uu[i]]]=min(mn[id[uu[i]]],ww[i]);
			now[id[uu[i]]]--;
		}
	}
	For(i,1,cnt)if(now[i]!=sz[i]-1){
		cout<<res<<endl;
		return 0;
	}//cout<<res<<endl;
	res=min(res+X,res+minn);
	cout<<res;
	return 0;
}