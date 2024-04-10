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

ll B=320;	// 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll  p[n];		// 
	P dp[n];		// first: second:
	REP(i,n) cin>>p[i];
	ll ca=0,cb=0;
	ll typ[m];
	P dat[m];
	REP(i,m) {
		cin>>typ[i];
		if(typ[i]==0) {
			cin>>dat[i].first>>dat[i].second;
			ca++;
		}
		else {
			cin>>dat[i].first;
			cb++;
		}
	}
	if(ca>=cb+20000) B=320;
	else B=810;
	ll sz=(n-1)/B+1;	// 
	REP(i,sz) {
		for(ll j=B-1; j>=0; j--) {
			if(i*B+j>=n) continue;
			if(i*B+j+p[i*B+j]>=(i+1)*B||i*B+j+p[i*B+j]>=n) {
				dp[i*B+j].first=1;
				dp[i*B+j].second=i*B+j;
			} else {
				dp[i*B+j].first=dp[i*B+j+p[i*B+j]].first+1;
				dp[i*B+j].second=dp[i*B+j+p[i*B+j]].second;
			}
		}
	}
	REP(q,m) {
		if(typ[q]==0) {
			ll a=dat[q].first,b=dat[q].second;
			a--;
			p[a]=b;
			ll num=a/B;	// a 
			for(ll i=a%B; i>=0; i--) {
				if(num*B+i+p[num*B+i]>=(num+1)*B||num*B+i+p[num*B+i]>=n) {
					dp[num*B+i].first=1;
					dp[num*B+i].second=num*B+i;
				} else {
					dp[num*B+i].first=dp[num*B+i+p[num*B+i]].first+1;
					dp[num*B+i].second=dp[num*B+i+p[num*B+i]].second;
				}
			}
		} else /* typ==1 */ {
			ll pos=dat[q].first;
			pos--;
			ll res=0;
			while(pos<n) {
				res+=dp[pos].first;
				if(pos/B+1==sz||dp[pos].second+p[dp[pos].second]>=n) {
					pos=dp[pos].second;
					break;
				} else {
					pos=dp[pos].second+p[dp[pos].second];
				}
			}
			cout<<pos+1<<" "<<res<<endl;
		}
	}
}