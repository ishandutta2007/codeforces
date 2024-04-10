#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,q;
ll d1[500001],b1[500001];
ll d2[500001],b2[500001];
vector<int>adj[500001];
vector<int>r[500001];
int cs[500001];
int bc[500001];

void kurorz(vector<int>&v){
	if(v.empty()) return;
	for(int i=0; i<v.size() ;i++) 
		if(v[i]>v.back()) swap(v[i],v.back());
	int orz=v.back();
	int mx=0;
	for(int i=0; i<v.size()-1 ;i++) mx=max(mx,v[i]);
	for(int i=0; i<v.size()-1 ;i++) cs[v[i]]++;
	int ptr=0;
	for(int i=0; i<=mx ;i++){
		for(int j=0; j<cs[i] ;j++) v[ptr++]=i;
		cs[i]=0;
	}
}
vector<pair<int,int> >s;
vector<pair<int,int> >t;
int cnt[500001],duh[500001];
void kuroni(int id,int p){
	s.clear();
	if(bc[id]==0) return;
	int mx=0;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		if(cur==bc[id]) continue;
		int ptr=0;
		for(auto t:r[cur]){
			cnt[t]++;
			duh[t]=max(duh[t],(int)r[cur].size()-ptr);
			mx=max(mx,t);
			ptr++;
		}
	}
	int ptr=0;
	for(auto t:r[bc[id]]){
		if(t>mx) break;
		cnt[t]++;
		duh[t]=max(duh[t],(int)r[bc[id]].size()-ptr);
		ptr++;
	}
	for(int i=0; i<=mx ;i++){
		for(int j=0; j<cnt[i] ;j++) s.push_back({i,duh[i]});
		cnt[i]=duh[i]=0;
	}
	ptr=-1;
	for(auto t:r[bc[id]]){
		ptr++;
		if(t<=mx) continue;
		s.push_back({t,r[bc[id]].size()-ptr});
		
	}
	//cout << "kuroni " << id << ' ' << s.size() << endl;
}
void dfs(int id,int p){
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
		if(d2[id]<d1[cur]+1){
			d2[id]=d1[cur]+1;
			b2[id]=cur;
		}
		if(d2[id]>d1[id]){
			swap(d1[id],d2[id]);
			swap(b1[id],b2[id]);
		}
		if(d1[cur]>=d1[bc[id]]) bc[id]=cur;
		r[id].push_back(d1[cur]+1);
	}
	/*cout << "r: ";
	for(auto cur:r[id]) cout << cur << ' ';
	cout << endl;*/
	kurorz(r[id]);
	/*cout << "r: ";
	for(auto cur:r[id]) cout << cur << ' ';
	cout << endl;*/
	//cout << "bc " << id << ' ' << bc[id] << endl;
}
vector<int>v;
ll ans[1000001];
ll ans2[1000001];
void dfs2(int id,int p,ll pd){
	bool duh=false;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		if(cur==b1[id]) dfs2(cur,id,max(pd,d2[id])+1);
		else dfs2(cur,id,max(pd,d1[id])+1);
		if(adj[cur].size()>=3) duh=true;
	}
	v.clear();
	for(auto cur:adj[id]){
		if(cur==p) continue;
		v.push_back(1+d1[cur]);
	}
	/*cout << "v:";
	for(auto cur:v) cout << cur << ' ';
	cout << endl;*/
	kurorz(v);
	/*cout << "v:";
	for(auto cur:v) cout << cur << ' ';
	cout << endl;*/
	if(id!=1) v.push_back(pd);
	for(int i=(int)v.size()-1; i>=1 ;i--){
		if(v[i]<v[i-1]) swap(v[i-1],v[i]);
	}
	int sz=v.size();
	if(v.size()>=2){
		int x=v.back();
		int y=v[v.size()-2];
		ans[x+y]=max(ans[x+y],2LL);
	}
	ans[1]=max(ans[1],(ll)v.size()+1);
	kuroni(id,p);
	int zs=s.size();
	/*cout << "s: ";
	for(auto cur:s) cout << "(" << cur.fi << ',' << cur.se << ") ";
	cout << endl; */
	for(int i=(int)s.size()-1; i>=1 ;i--){
		s[i-1].se=max(s[i-1].se,s[i].se);
	}
	s.push_back({(ll)1e9,0});
	for(int i=0; i<(int)v.size()-1 ;i++){
		int cur=v[i];
		ans[cur*2]=max(ans[cur*2],(ll)sz-i);
		if(v[i+1]!=v[i]) ans[cur*2+1]=max(ans[cur*2+1],(ll)sz-i);
	}
	for(int i=0; i<(int)v.size() ;i++){
		int cur=v[i];
		int j=lower_bound(s.begin(),s.end(),(pair<int,int>){cur,0})-s.begin();
		ans2[cur*2]=max(ans2[cur*2],(ll)(sz-i)+s[j].se-1);
	}
	for(int i=0; i<(int)s.size()-1 ;i++){
		int cur=s[i].fi;
		int j=lower_bound(v.begin(),v.end(),cur)-v.begin();
		ans2[cur*2]=max(ans2[cur*2],(ll)(sz-j)+s[i].se-1);
	}
	//cout << id << ' ' << ans[2] << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0,0);
	for(int i=2*n-1; i>=1 ;i--) ans[i]=max(ans[i+1],ans[i]);
	for(int i=2*n-2; i>=2 ;i--) ans2[i]=max(ans2[i+2],ans2[i]);
	for(int i=1; i<=n ;i++){
		ans[i]=max(ans[i],ans2[i]);
		cout << max(ans[i],1LL) << ' ';
	}
	cout << endl;
}