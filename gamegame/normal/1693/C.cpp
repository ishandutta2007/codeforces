#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int n,m;
vector<int>adj[N],rev[N];
int in[N];
ll d[N];
bool vis[N];
typedef pair<ll,int> pli;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
		in[u]++;
	}
	for(int i=1; i<=n ;i++) d[i]=1e9;
	d[n]=0;
	priority_queue<pli,vector<pli>,greater<pli> >pq;
	pq.push({0,n});
	while(!pq.empty()){
		auto cur=pq.top();pq.pop();
		if(vis[cur.se]) continue;
		int x=cur.se;
		vis[x]=true;
		for(auto c:rev[x]){
			in[c]--;
			if(d[c]>d[x]+in[c]+1){
				d[c]=d[x]+in[c]+1;
				pq.push({d[c],c});
			}
		}/*
		for(int i=1; i<=n ;i++){
			cout << d[i] << ' ';
		}
		cout << endl;*/
	}
	cout << d[1] << '\n';
}