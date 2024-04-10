#include<bits/stdc++.h>
using namespace std;
#define N 400020
typedef long long ll;
int n,m,len,ans[N];
ll b[N];
vector<int> G[N];
bool vis[N],live[N];
void adde(int u,int v){
	G[u].push_back(v),G[v].push_back(u);
}
struct Query{
	ll l,r;int opt;
}q[N];
class Union_Set{
public:
	int f[N];
	void init(int n){for(int i=1;i<=n;++i)f[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	void Merge(int x,int y){int fx=getf(x),fy=getf(y);if(fx^fy)f[fy]=fx;}
}S;
void Insert(int u){
	live[u]=1;
	for(auto v:G[u])if(live[v])S.Merge(u,v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	b[len=1]=0;
	for(int i=1;i<=m;++i){
		string s;
		cin>>s>>q[i].l>>q[i].r;
		q[i].opt=s[0]=='b';
		if(q[i].opt){b[++len]=q[i].l,b[++len]=q[i].r+1;}
	}
	b[++len]=1LL<<n;
	sort(b+1,b+len+1);
	for(int i=1,jb=len;i<jb;++i){
		ll l=b[i],r=b[i+1]-1;
		if(l>=r)continue;
		ll x=1LL<<(63-__builtin_clzll(l^r));
		b[++len]=x|(l^(l&(x-1)));
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-2;
	for(int i=0;i<n;++i){
		for(int j=0;j<=1;++j){
			for(int k=1,p=1;k<=len;++k){
				if((b[k]>>i&1)==j){
					ll v=b[k]^(1LL<<i);
					while(v>=b[p+1])++p;
					if(p^k)adde(p,k);
				}
			}
		}	
	}
	for(int i=1;i<=m;++i){
		if(q[i].opt){
			int l=lower_bound(b+1,b+len+1,q[i].l)-b;
			int r=upper_bound(b+1,b+len+1,q[i].r)-b-1;
			for(int j=l;j<=r;++j)vis[j]=1;
		}
	}
	S.init(len);
	for(int i=1;i<=len;++i)if(!vis[i])Insert(i);
	for(int i=m;i>=1;--i){
		if(q[i].opt){
			int l=lower_bound(b+1,b+len+1,q[i].l)-b;
			int r=upper_bound(b+1,b+len+1,q[i].r)-b-1;
			for(int j=l;j<=r;++j)Insert(j);
		}
		else{
			int u=upper_bound(b+1,b+len+1,q[i].l)-b-1;
			int v=upper_bound(b+1,b+len+1,q[i].r)-b-1;
			ans[i]=S.getf(u)==S.getf(v);
		}
	}
	for(int i=1;i<=m;++i){
		if(!q[i].opt)cout<<ans[i]<<'\n';
	}
	return 0;
}