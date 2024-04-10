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

ll B=100;	// 
ll sz=0;	// 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	sz=(n-1)/B+1;
	bitset<10010> buc[sz];
	REP(i,sz) REP(j,10010) {
		if(j==0) buc[i][j]=1;
		else buc[i][j]=0;
	}
	vector<ll> que[n];
	REP(i,q) {
		ll a,b,x;
		cin>>a>>b>>x;
		a--;
		b--;
		if(b-a+1<=B+1) {
			FOR(i,a,b+1) que[i].pb(x);
			continue;
		}
		while(a%B!=0&&a<=b) {
			que[a].pb(x);
			a++;
		}
		while((b+1)%B!=0&&b>a) {
			que[b].pb(x);
			b--;
		}
		while(a<b) {
			ll pos=a/B;
			buc[pos]|=(buc[pos]<<x);
			a+=B;
		}
	}
	bitset<10010> ans(0);
	REP(i,n) {
		bitset<10010> bi=buc[i/B];
		REP(j,(ll)que[i].size()) bi|=(bi<<que[i][j]);
		ans|=bi;
	}
	vector<ll> ret;
	FOR(i,1,n+1) if(ans[i]) ret.pb(i);
	cout<<(ll)ret.size()<<endl;
	DUMP(ret);
}