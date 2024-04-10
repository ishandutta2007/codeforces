#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
template<class T>
inline bool upmn(T &x,T y){return x>y?x=y,1:0;}
const ll INF=~0uLL>>2;
int n,m;
struct P{
	ll w;
	int x,y;
	bool operator<(const P&t)const{
		return w>t.w;
	}
};
ll solve(){
	vector<string> s(n);
	int W1,W2;
	cin>>W1>>W2;
	For(i,0,n) cin>>s[i];
	dbg(n, m);
	vector<vector<ll>> dist(n, vector<ll>(m, INF));
	priority_queue<P> Q;
	For(i,0,n) For(j,0,m) {
		if(s[i][j] == '.') {
			dist[i][j] = 0;
			Q.push((P){0LL,i,j});
		}
	}
	auto chk=[&](int i,int j){
		return i>=0 && i<n && j>=0 && j<m && s[i][j]!='#' && s[i][j] != '.';
	};
	while(!Q.empty()){
		auto [w,x,y]=Q.top();Q.pop();
		static const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
		For(i,0,4){
			int u=x+dx[i];
			int v=y+dy[i];
			if(!chk(u,v)) continue;
			if(s[u][v]=='U') {
				int p=u+1,q=v;
				if(upmn(dist[p][q], w+(i<2?W1:W2))) Q.push((P){dist[p][q], p,q});
			}
			if(s[u][v]=='D') {
				int p=u-1,q=v;
				if(upmn(dist[p][q], w+(i<2?W1:W2))) Q.push((P){dist[p][q], p,q});
			}
			if(s[u][v]=='L') {
				int p=u,q=v+1;
				if(upmn(dist[p][q], w+(i>=2?W1:W2))) Q.push((P){dist[p][q], p,q});
			}
			if(s[u][v]=='R') {
				int p=u,q=v-1;
				if(upmn(dist[p][q], w+(i>=2?W1:W2))) Q.push((P){dist[p][q], p,q});
			}
		}
	}
	ll ans=INF;
	For(i,0,n) For(j,0,m) {
		if(i<n-1) upmn(ans, dist[i][j]+dist[i+1][j]);
		if(j<m-1) upmn(ans, dist[i][j]+dist[i][j+1]);
	}
	if(ans==INF)ans=-1;
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n>>m) {
		cout<<solve()<<endl;
	}
}