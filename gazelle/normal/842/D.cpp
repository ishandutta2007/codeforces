#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i, m) for(long long i=0; i<m; ++i)
#define FOR(i, n, m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<ll> vl;
typedef vector<vector<ll> > vll;

vector<ll> c((1<<22),0);
int main() {
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
	ll size=a.size();
	REP(i,size) {
		string buf="";
		ll bufn=a[i];
		REP(j,20) {
			if(bufn%2==1) buf='1'+buf;
			else buf='0'+buf;
			bufn/=2;
		}
		ll roc=1;
		++c[roc];
		REP(j,20) {
			if(buf[j]=='0') {
				roc=roc*2;
				++c[roc];
			} else {
				roc=roc*2+1;
				++c[roc];
			}
		}
	}
	vector<ll> bits(20,0);
	REP(i,m) {
		ll x;
		cin>>x;
		vector<ll> bit(20,0);
		ll buf=x;
		REP(j,20) {
			if(buf%2==1) ++bit[19-j];
			buf/=2;
		}
		REP(j,20) bits[j]=bits[j]^bit[j];
		ll roc=1;
		string res="";
		REP(j,20) {
			if(bits[j]==1) {
				if((1<<(19-j))-c[roc*2+1]>0) {
					res+='1';
					roc=roc*2+1;
				}
				else {
					res+='0';
					roc=roc*2;
				}
			} else {
				if((1<<(19-j))-c[roc*2]>0) {
					res+='0';
					roc=roc*2;
				}
				else {
					res+='1';
					roc=roc*2+1;
				}
			}
		}
		ll ans=0;
		ll k=1;
		REP(j,20) {
			if(bits[19-j]==1) {
				if(res[19-j]=='0') {
					ans+=k;
				}
			} else {
				if(res[19-j]=='1') {
					ans+=k;
				}
			}
			k*=2;
		}
		cout<<ans<<endl;
	}
}