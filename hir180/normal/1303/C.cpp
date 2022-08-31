#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int t;
vector<int>edge[26];
string str,ret;
bool used[26];
void dfs(int v){
	if(used[v])return; ret.pb('a'+v); used[v] = 1;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(!used[to]) dfs(to);
	}
}
void solve(){
	ret = "";
	rep(i,26) edge[i].clear();
	memset(used,0,sizeof(used));
	cin >> str;
	int n = str.size();
	rep(i,n-1){
		int a = str[i]-'a';
		int b = str[i+1]-'a';
		edge[a].pb(b);
		edge[b].pb(a);
	}
	rep(i,26) { SORT(edge[i]); ERASE(edge[i]); }
	rep(i,26) {
		if(!used[i] && edge[i].size() <= 1) dfs(i);
	}
	if(ret.size() < 26){
	    puts("NO"); return ;
	}
	bool ok = 1;
	rep(i,n-1){
		int a = str[i]-'a';
		int b = str[i+1]-'a';
		int pos,pos2;
		rep(ii,ret.size()){
			if(ret[ii] == str[i]) pos = ii;
			if(ret[ii] == str[i+1]) pos2 = ii;
		}
		if(abs(pos-pos2) != 1) ok = 0;
	}
	if(!ok) puts("NO");
	else{
		puts("YES");
		cout << ret << endl;
	}
}
int main(){
	cin>>t;
	while(t--) solve();
}