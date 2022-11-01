#include<bits/stdc++.h>
#include<random>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll n,m;
bool det(vector<vector<char>>& g, P p) {
	if(p.first<=0||p.first>=n-1||p.second<=0||p.second>=m-1) return false;
	bool ret=true;
	for(int i = -1; i<=1; i++) for(int j=-1; j<=1; j++) {
		if(i==0&&j==0) continue;
		if(g[p.first+i][p.second+j]=='.') ret=false;
	}
	return ret;
}

int main() {
	cin.tie(0);
	cin>>n>>m;
	vector<vector<char>> g(n,vector<char>(m));
	REP(i,n) REP(j,m) cin>>g[i][j];
	REP(i,n) REP(j,m) {
		if(g[i][j]=='.') continue;
		bool hoge=false;
		for(int k = -1; k<=1; k++) for(int l=-1; l<=1; l++) {
			if(k==0&&l==0) continue;
			if(det(g,P(i+k,j+l))) hoge=true;
		}
		if(!hoge) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}