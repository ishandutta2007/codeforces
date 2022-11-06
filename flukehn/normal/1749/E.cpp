#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
int n,m;
template<class T>
inline bool upmn(T &x, T y){return x>y?x=y,1:0;}
void solve(){
	cin>>n>>m;
	vector<string> s(n);
	For(i,0,n) cin>>s[i];
	using pii=pair<int,int>;
	vector<vector<pii>> pre(n, vector<pii>(m, pii(-1,-1)));
	vector<vector<int>> need(n, vector<int>(m, m*n+1));
	//For(i,0,n) For(j,0,m) debug(pre[i][j]<<" \n"[j+1==m]);
	auto chk=[&](int i,int j){
		if(i<0||i>=n || j<0||j>=m) return 0;
		if(s[i][j]=='#') return 1;
		if(i&&s[i-1][j]=='#') return 0;
		if(i<n-1&&s[i+1][j]=='#') return 0;
		if(j&&s[i][j-1]=='#')return 0;
		if(j<m-1&&s[i][j+1]=='#') return 0;
		return 1;
	};
	
	deque<pii> q;
	For(i,0,n) {
		if(chk(i,0)) {
			pre[i][0]= pii(-1,-1);
			need[i][0]= s[i][0]!='#';
			
			if(s[i][0] == '.') {
				q.push_back(pii(i,0));
			}else{
				q.push_front(pii(i,0));
			}
		}
	}
	auto G=[&](int x,int y,int i,int j){
		if(!chk(x,y)) return;
		int v=s[x][y]=='.';
		if(upmn(need[x][y], need[i][j]+v)){
			pre[x][y]=pii(i,j);
			if(v) q.push_back(pii(x,y));
			else q.push_front(pii(x,y));
		}
	};
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop_front();
		G(x-1,y-1,x,y);
		G(x+1,y-1,x,y);
		G(x-1,y+1,x,y);
		G(x+1,y+1,x,y);
	}
	int u=-1,v=m-1;
	int ans=m*n+1;
	For(i,0,n) if(need[i][m-1] < n*m) {
		if(upmn(ans, need[i][m-1])){
			u=i;
		}
	}
	if (u>=0){
		while(u>=0&&v>=0&&need[u][v]) {
			//dbg(j, p);
			s[u][v]='#';
			auto [x,y]=pre[u][v];
			u=x,v=y;
		}
		cout<<"YES\n";
		For(i,0,n) cout<<s[i]<<'\n';
	} else {
		cout<<"NO\n";
	}
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}