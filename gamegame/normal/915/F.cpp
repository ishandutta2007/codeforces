#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
vector<int>adj[1000001];
int s[1000001];
int par[1000001];
int a[1000001];
pair<int,int>b[1000001];
bool in[1000001];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
void join(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	s[y]+=s[x];
	par[x]=y;
}
ll mini,maxi;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]=make_pair(a[i],i);
	}
	sort(b+1,b+n+1);
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n ;i++){
		par[i]=i;
		s[i]=1;
	}
	for(int i=1; i<=n ;i++){
		int cur=b[i].second;
		int curs=0;
		for(int j=0; j<adj[cur].size() ;j++){
			if(in[adj[cur][j]]) curs+=s[find(adj[cur][j])];
		}
		ll sum=0;
		for(int j=0; j<adj[cur].size() ;j++){
			if(in[adj[cur][j]]){
				int tmp=s[find(adj[cur][j])];
				sum+=1LL*a[cur]*tmp*(curs-tmp);
				join(adj[cur][j],cur);
			}
		}
		maxi+=sum/2+1LL*curs*a[cur];
		in[cur]=true;
	}
	for(int i=1; i<=n ;i++){
		par[i]=i;
		s[i]=1;
		in[i]=false;
	}
	for(int i=n; i>=1 ;i--){
		int cur=b[i].second;
		int curs=0;
		for(int j=0; j<adj[cur].size() ;j++){
			if(in[adj[cur][j]]) curs+=s[find(adj[cur][j])];
		}
		ll sum=0;
		for(int j=0; j<adj[cur].size() ;j++){
			if(in[adj[cur][j]]){
				int tmp=s[find(adj[cur][j])];
				sum+=1LL*a[cur]*tmp*(curs-tmp);
				join(adj[cur][j],cur);
			}
		}
		mini+=sum/2+1LL*curs*a[cur];
		in[cur]=true;
	}
	cout << maxi-mini << endl;
}