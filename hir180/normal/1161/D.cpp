#include <bits/stdc++.h>
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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

vector<int>edge[4005];
string s;
int n;
int must[4005];

bool used[4005];

struct uf{
	int par[4005],ran[4005];
	void init(){ for(int i=0;i<4005;i++) par[i] = i,ran[i] = 0; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}U;
bool ex[4005][2];
int main(){
	cin>>s;
	n = s.size();
	ll ret = 0;
	for(int a=1;a<n;a++){
		for(int i=0;i<4005;i++){
			edge[i].clear();
			must[i] = -1;
			used[i] = 0;
			ex[i][0] = ex[i][1] = 0;
		}
		U.init();
		must[0] = 1;
		must[n] = 1;
		for(int i=0;i<n-1;i++){
			U.unite(i,n-1-i);
			U.unite(i+2001,n-1-i+2001);
			//edge[i].pb(mp(n-1-i,0));
		}
		for(int i=n;i<n+a;i++){
			U.unite(i,2*n+a-1-i);
			U.unite(i+2001,2*n+a-1-i+2001);
			//edge[i].pb(mp(2*n+a-1-i,0));
		}
		for(int i=0;i<n;i++){
			if(i<n-a){
				if(s[i] == '?') continue;
				must[i] = s[i]-'0';
			}
			else{
				if(s[i] == '?') continue;
				if(s[i] == '0'){
					U.unite(i,i+a);
					U.unite(i+2001,i+a+2001);
					//edge[i].pb(mp(i+a,s[i]-'0'));
					//edge[i+a].pb(mp(i,s[i]-'0'));
				}
				else{
					U.unite(i,i+a+2001);
					U.unite(i+2001,i+a);
				}
			}
		}
		for(int i=0;i<n+a;i++){
			if(must[i] != -1){
				ex[U.find(i)][must[i]] = 1;
				ex[U.find(i+2001)][1-must[i]] = 1;
			}
		}
		bool FAIL = 0;
		for(int i=0;i<4005;i++){
			if(ex[i][0] && ex[i][1]){
				FAIL = 1;
				break;
			}
		}
		if(FAIL) continue;
		ll ans = 1;
		for(int i=0;i<n+a;i++){
			if(U.find(i) != i) continue;
			if(ex[i][0] || ex[i][1]) continue;
			else ans = ans*2LL%mod;
		}
		ret += ans;
		//cout << ans << " " << a << endl;
	}
	cout<<(ret%mod+mod)%mod<<endl;
}