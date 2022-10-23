#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
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

int n,m,p[maxn],fl;
vector<pii>e1[maxn],e2[maxn];
void adde1(int u,int v,int w){
	e1[u].pb(mkp(v,w));
	e1[v].pb(mkp(u,w));
}
void adde2(int u,int v,int w){
	e2[u].pb(mkp(v,w));
	e2[v].pb(mkp(u,w));
} 

int c1,c2,s1[maxn],s2[maxn],id1[maxn],id2[maxn],vis[maxn];
void dfs1(int u){
	id1[u]=c1;
	if(u<=n)s1[c1]++;
	for(auto t:e1[u])if(!id1[t.fi])dfs1(t.fi);
}
void dfs2(int u){
	id2[u]=c2;
	if(u<=n)s2[c2]++;
	for(auto t:e2[u])if(!id2[t.fi])dfs2(t.fi);
}

vi o;

bool cmp(pii x,pii y){
	return x.se<y.se;
}

bool chk(int u){
	o.pb(u);
	vis[p[u]]=1;
	if(e1[u].size() != e2[p[u]].size()) return 0;
	for(int i=0;i<e1[u].size();++i){
		int v1=e1[u][i].fi,v2=e2[p[u]][i].fi;
		int w1=e1[u][i].se,w2=e2[p[u]][i].se;
		if(w1!=w2)return 0;
		if(p[v1] || vis[v2]) {
			if(p[v1]!=v2) return 0;
			continue;
		} else {
			p[v1]=v2;
			if(!chk(v1)) return 0;
		}
	} return 1;
}

signed main()
{
	n=read(),m=read(),fl=n>m;
	For(i,1,n)
		For(j,1,m){
			int a=read(); if(!a)continue;
			if(fl) adde1(j,m+i,a);
			else adde1(i,j+n,a);
		}
	For(i,1,n)
		For(j,1,m){
			int a=read(); if(!a)continue;
			if(fl) adde2(j,m+i,a);
			else adde2(i,j+n,a);
		}
	if(fl)swap(n,m);
	For(i,1,n+m)sort(e1[i].begin(),e1[i].end(),cmp),sort(e2[i].begin(),e2[i].end(),cmp);
	For(i,1,n+m){
		if(!id1[i])++c1,dfs1(i);
		if(!id2[i])++c2,dfs2(i);
	}
	For(i,1,n){
		if(p[i])continue;
		For(j,1,n)
			if(!vis[j] && s1[id1[i]]==s2[id2[j]]){
	//			cout<<"ck "<<i<<" "<<j<<"\n";
				p[i]=j; o.clear();
				if(chk(i))break;
				for(auto x:o)vis[p[x]]=0,p[x]=0; o.clear();
			}
	//	cout<<"i: "<<i<<" "<<p[i]<<"\n";
		if(!p[i])puts("-1"),exit(0);
	}
	
//	For(i,1,n)assert(p[i]>0);
	
	vi tmp;
	For(i,n+1,n+m)if(!vis[i])tmp.pb(i);
	For(i,n+1,n+m)if(!p[i])p[i]=tmp.back(),tmp.pop_back();
	
//	For(i,1,n+m)assert(p[i]>0);
	
//	if(n==392&&m==392)exit(0);
	vector<vi>out;
	For(i,1,n)while(p[i]!=i)out.pb({fl?2:1,i,p[i]}),swap(p[i],p[p[i]]);
	For(i,1,m)while(p[n+i]!=n+i)out.pb({fl?1:2,i,p[n+i]-n}),swap(p[n+i],p[p[n+i]]);
	cout<<out.size()<<"\n";
	for(auto t:out){for(auto p:t)cout<<p<<" ";cout<<"\n";}
	return 0;
}