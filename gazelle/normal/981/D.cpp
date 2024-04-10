#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll n,k;
vector<ll> a;
vector<vector<vector<ll>>> memo(60,vector<vector<ll>>(60,vector<ll>(61,-1)));
bool dfs(bitset<60>& tgt, ll pos, ll num, ll idx) {
	if(num==0) return true;
	if(memo[pos][num][idx]!=-1) {
		if(memo[pos][num][idx]==0) return false;
		if(memo[pos][num][idx]==1) return true;
	}
	if(pos>=n) return false;
	if(num==1) {
		ll sum=0;
		FOR(i,pos,n) sum+=a[i];
		bitset<60> bi(sum);
		bool ok=true;
		for(ll i=59; i>=0; i--) {
			if(i==idx) {
				if(!(bi[i])) ok=false;
				break;
			}
			if(tgt[i]&&!(bi[i])) ok=false;
		}
		return ok;
	}
	bool ret=false;
	ll sum=0;
	FOR(i,pos,n) {
		sum+=a[i];
		bitset<60> bi(sum);
		bool ok=true;
		for(ll j=59; j>=0; j--) {
			if(j==idx) {
				if(!(bi[j])) ok=false;
				break;
			}
			if(tgt[j]&&!(bi[j])) ok=false;
		}
		if(ok) ret=ret|dfs(tgt,i+1,num-1,idx);
	}
	if(ret) memo[pos][num][idx]=1;
	else memo[pos][num][idx]=0;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	a.resize(n);
	REP(i,n) cin>>a[i];
	ll lb=0, ub=(1ll<<60)-1;
	while(ub-lb>1) {
		REP(i,60) REP(j,60) REP(k,61) memo[i][j][k]=-1;
		//ll m=15;
		ll m=(lb+ub)/2;
		//if(m<24) cout<<m<<endl;
		bitset<60> tgt(m);
		bool d=false;
		ll sum=0;
		REP(i,n) {
			sum+=a[i];
			bitset<60> bi(sum);
			bool ok=true;
			vector<ll> idx;
			for(ll j=59; j>=0; j--) {
				if(!tgt[j]&&bi[j]) {
					idx.pb(j);
				}
				if(tgt[j]&&!bi[j]) {
					ok=false;
					break;
				}
			}
			if(ok) d=d|dfs(tgt,i+1,k-1,60);
			REP(j,(ll)idx.size()) d=d|dfs(tgt,i+1,k-1,idx[j]);
		}
		if(d) lb=m;
		else ub=m;
	}
	cout<<lb<<endl;
}