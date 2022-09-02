#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,pair<double,double> > P2;
typedef pair<pair<double,double>,P> P3;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[105][105][2][105];
vector<P>edge[105];
int n,m;
int rec(int f,int s,int w,int cur){
	if(dp[f][s][w][cur] >= 0) return dp[f][s][w][cur];
	if(w == 0){
		rep(i,edge[f].size()){
		    if(edge[f][i].sc < cur) continue;
			if(rec(edge[f][i].fi,s,1-w,edge[f][i].sc)) return dp[f][s][w][cur] = 1;
		}
		return dp[f][s][w][cur] = 0;
	}
	else{
		rep(i,edge[s].size()){
		    if(edge[s][i].sc < cur) continue;
			if(!rec(f,edge[s][i].fi,1-w,edge[s][i].sc)) return dp[f][s][w][cur] = 0;
		}
		return dp[f][s][w][cur] = 1;
	}
}
int main(){
	cin>>n>>m;
	rep(i,m){
		int a,b; string s;
		cin>>a>>b>>s;
		edge[a].pb(mp(b,s[0]-'a'));
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(rec(i,j,0,0)) cout<<"A";
			else cout<<"B";
		}
		cout<<endl;
	}
}