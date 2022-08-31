#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll mod2=998244853;
#define fi first
#define se second
int n,m;
int len[100001];
string s[100001];
vector<pair<int,int> >adj[100001];
int d[100001];
bool vis[100001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
const int ts=2e7+1;
int sz=1;
int ln[ts];
int ans[ts],ans2[ts];
int lc[ts],rc[ts];
ll pw[500001],pw2[500001];
int rt[ts];
bool vis2[100001];
int maxd;
bool duh(int u,int v){
	if(v==0) return false;
	if(u==0) return true;
	if(ln[u]!=ln[v]) return ln[u]>ln[v];
	if(ans2[u]==ans2[v]) return false;
	int l=1,r=maxd;
	while(l!=r){
		int mi=(l+r)/2;
		if(ans2[lc[u]]==ans2[lc[v]]){
			l=mi+1;u=rc[u];v=rc[v];
		}
		else{
			r=mi;u=lc[u];v=lc[v];
		}
	}
	return ans2[u]>ans2[v];
}
class cmp{
	public:
	bool operator()(pair<int,int>x,pair<int,int>y){
		int u=x.fi;int v=y.fi;
		return duh(u,v);
	}
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp>pq2;
int dog(int id,int l,int r,int c){
	if(l==r){
		++sz;
		ln[sz]=1;ans[sz]=ans2[sz]=c;
		return sz;
	}
	int mi=(l+r)/2;
	int tlc=lc[id];int trc=rc[id];
	if(ln[id]>=mi-l+1) trc=dog(rc[id],mi+1,r,c);
	else tlc=dog(lc[id],l,mi,c);
	++sz;
	ln[sz]=ln[id]+1;
	lc[sz]=tlc;rc[sz]=trc;
	ans[sz]=(1LL*ans[tlc]*pw[ln[trc]]+ans[trc])%mod;
	ans2[sz]=(1LL*ans2[tlc]*pw2[ln[trc]]+ans2[trc])%mod2;
	return sz;
}
int append(int id,int y){
	vector<int>gay;
	while(y>0){
		gay.push_back(y%10);y/=10;
	}
	reverse(gay.begin(),gay.end());
	for(auto cur:gay) id=dog(id,1,maxd,cur);
	return id;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		len[i]=len[i/10]+1;
		s[i]=s[i/10]+(char)(i%10+48);
	}
	for(int i=1; i<=n ;i++){
		d[i]=1e9;
		sort(adj[i].begin(),adj[i].end());
	}
	d[1]=0;
	pq.push({0,1});
	while(!pq.empty()){
		int cur=pq.top().se;pq.pop();
		if(vis[cur]) continue;
		vis[cur]=true;
		maxd=max(maxd,d[cur]);
		for(auto newi:adj[cur]){
			if(d[newi.fi]>d[cur]+len[newi.se]){
				d[newi.fi]=d[cur]+len[newi.se];
				pq.push({d[newi.fi],newi.fi});
			}
		}
	}
	pw[0]=1;pw2[0]=1;
	for(int i=1; i<=maxd ;i++) pw[i]=pw[i-1]*10%mod,pw2[i]=pw2[i-1]*13%mod2;
	rt[1]=1;
	pq2.push({1,1});
	while(!pq2.empty()){
		int cur=pq2.top().se;
		pq2.pop();
		if(vis2[cur]) continue;
		vis2[cur]=true;
		for(auto newi:adj[cur]){
			int tmp=append(rt[cur],newi.se);
			if(d[newi.fi]==d[cur]+len[newi.se] && duh(rt[newi.fi],tmp)){
				rt[newi.fi]=tmp;
				pq2.push({tmp,newi.fi});
			}
		}
	}
	for(int i=2; i<=n ;i++){
		cout << ans[rt[i]] << '\n';
	}
}