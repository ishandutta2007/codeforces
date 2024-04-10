#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int iu=17;
int n,q;
ll e[200001];
int anc[200001][18];
ll pto[200001][18];
ll d[200001];

vector<pair<ll,int> >adj[200001];
pair<ll,pair<int,int> >ed[200001];
void dfs(int id){
	for(auto c:adj[id]){
		if(c.se==anc[id][0]) continue;
		d[c.se]=d[id]+1;
		anc[c.se][0]=id;
		pto[c.se][0]=c.fi;
		for(int i=0; i<iu ;i++){
			anc[c.se][i+1]=anc[anc[c.se][i]][i];
			pto[c.se][i+1]=max(pto[c.se][i],pto[anc[c.se][i]][i]);
		}
		dfs(c.se);
	}
}
int kth(int x,int k){
	for(int i=iu; i>=0 ;i--){
		if((k>>i)&1) x=anc[x][i];
	}
	return x;
}
ll go(int x,int k){
	ll res=0;
	for(int i=iu; i>=0 ;i--){
		if((k>>i)&1){
			res=max(res,pto[x][i]);
			x=anc[x][i];
		}
	}
	return res;
}
int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	x=kth(x,d[x]-d[y]);
	//cout << "lca !!!" << endl;
	//cout << x << ' ' << y << endl;
	if(x==y) return x;
	for(int i=iu; i>=0 ;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
ll get_toll(int x,int y){
	int z=lca(x,y);
	return max(go(x,d[x]-d[z]),go(y,d[y]-d[z]));
}
pair<pair<ll,int>,int>qr[200001];
ll ans1[200001],ans2[200001];

int p[200001];
int king[200001];//one of the max enjoy
ll city[200001];//toll to traverse between max enjoy

int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n ;i++) cin >> e[i];
	for(int i=1; i<n ;i++){
		int u,v;ll c,t;
		cin >> u >> v >> c >> t;
		adj[u].push_back({t,v});
		adj[v].push_back({t,u});
		ed[i]={c,{u,v}};
	}
	dfs(1);
	sort(ed+1,ed+n);
	reverse(ed+1,ed+n);
	for(int i=1; i<=q ;i++){
		cin >> qr[i].fi.fi >> qr[i].fi.se;
		qr[i].se=i;
	}
	sort(qr+1,qr+q+1);
	reverse(qr+1,qr+q+1);
	int ptr=0;
	for(int i=1; i<=n ;i++){
		p[i]=i;
		king[i]=i;
		city[i]=0;
	}
	/*cout << "qruerwerew" << endl;
	for(int i=1; i<=5 ;i++) cout << d[i] << ' ';
	cout << endl;
	cout << lca(2,4) << endl;
	cout << get_toll(2,4) << endl;*/
	for(int i=1; i<=q ;i++){
		while(ptr<n-1 && ed[ptr+1].fi>=qr[i].fi.fi){
			++ptr;//insert(ptr)
			int u=ed[ptr].se.fi;
			int v=ed[ptr].se.se;
			u=find(u);v=find(v);
			if(e[king[u]]!=e[king[v]]){
				if(e[king[u]]<e[king[v]]) p[u]=v;
				else p[v]=u;
			}
			else{
				p[v]=u;
				city[u]=max(max(city[u],city[v]),get_toll(king[u],king[v]));
			}
		}
		int x=qr[i].fi.se;
		int y=find(x);
		ll res=max(get_toll(x,king[y]),city[y]);
		ans1[qr[i].se]=e[king[y]];
		ans2[qr[i].se]=res;
	}
	for(int i=1; i<=q ;i++) cout << ans1[i] << ' ' << ans2[i] << '\n';
}