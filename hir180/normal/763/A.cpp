#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef complex<double> pt;
int n,c[100005];;
vector<int>edge[100005];
int bad[100005],C;
bool dfs(int v,int u,int col){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		if(col != -1 && c[edge[v][i]] != col) return false;
		if(!dfs(edge[v][i],v,c[edge[v][i]])) return false;
	}
	return true;
}
int main(){
	cin>>n;
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	repn(i,n)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge[i].size();j++){
			if(c[i] != c[edge[i][j]]){
				bad[i]++;
				bad[edge[i][j]]++;
				C++;
			}
		}
	}
	if(C==0){
	    puts("YES");
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(bad[i] != C) continue;
		bool flag = dfs(i,-1,-1);
		if(flag){
			puts("YES");
			cout<<i<<endl;
			return 0;
		}
	}
	puts("NO");
}