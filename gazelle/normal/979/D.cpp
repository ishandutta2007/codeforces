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

struct query {
	ll x;
	ll s;
	ll num;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin>>q;
	vector<ll> aprd(100010,-1);
	vector<vector<query>> que(100010);
	REP(i,q) {
		ll t;
		cin>>t;
		if(t==1) {
			ll u;
			cin>>u;
			if(aprd[u]==-1) aprd[u]=i;
		} else {
			query tmp;
			ll x,k,s;
			cin>>x;
			cin>>k;
			cin>>s;
			tmp.x=x;
			tmp.s=s;
			tmp.num=i;
			que[k].pb(tmp);
		}
	}
	vector<P> ans;
	for(ll i=1; i<100010; i++) {
		vector<P> tl3;
		vector<query> tl2;
		vector<query> tl;
		for(ll j=1; i*j<100010; j++) {
			if(aprd[i*j]!=-1) {
				query tmp;
				tmp.x=-1;
				tmp.s=i*j;
				tl3.pb(P(aprd[i*j],(ll)tl3.size()));
				tl2.pb(tmp);
			}
		}
		REP(j,(ll)que[i].size()) {
			tl3.pb(P(que[i][j].num,(ll)tl3.size()));
			tl2.pb(que[i][j]);
		}
		sort(ALL(tl3));
		tl.resize((ll)tl3.size());
		set<ll> s;
		REP(j,(ll)tl3.size()) {
			tl[j]=tl2[tl3[j].second];
		}
		REP(j,(ll)tl.size()) {
			query tmp=tl[j];
			if(tmp.x==-1) {

				//cout<<i<<":"<<tmp.s<<endl;

				s.insert(tmp.s);
				continue;
			}
			//cout<<i<<":"<<tmp.x<<" "<<tmp.s<<endl;
			bitset<17> bi(tmp.x);
			bitset<17> ub((1ll<<17)-1);
			bitset<17> lb(0);
			if((ll)s.size()==0||*(s.begin())>tmp.s-tmp.x) {
				ans.pb(P(tmp.num,-1));
				continue;
			}
			if(tmp.x%i) {
				ans.pb(P(tmp.num,-1));
				continue;
			}
			for(ll k=16; k>=0; k--) {
				//if(i==3) cout<<lb.to_ullong()<<" "<<ub.to_ullong()<<endl;
				if(bi[k]==0) {
					lb[k]=1;
					auto ite=s.lower_bound(lb.to_ullong());
					if(ite==s.end()) {
						lb[k]=0;
						ub[k]=0;
						continue;
					}
					ll buf=*ite;
					//cout<<*ite<<endl;
					if(buf<=ub.to_ullong()&&buf<=tmp.s-tmp.x) {
						ub[k]=1;
					} else {
						lb[k]=0;
						ub[k]=0;
					}
				} else {
					ll buf=*(s.lower_bound(lb.to_ullong()));
					lb[k]=1;
					if(buf<lb.to_ullong()) {
						lb[k]=0;
						ub[k]=0;
					} else {
						ub[k]=1;
					}
				}
				//if(i==3) cout<<i<<":"<<lb[k]<<endl;
			}
			ans.pb(P(tmp.num,lb.to_ullong()));
		}
	}
	sort(ALL(ans));
	REP(i,(ll)ans.size()) cout<<ans[i].second<<endl;
}