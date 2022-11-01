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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<ll> a(6);
	REP(i,6) cin>>a[i];
	REP(i,6) {
		REP(j,6) {
			REP(k,6) {
				if(i==j||j==k||k==i) continue;
				ll sum1=0,sum2=0;
				REP(l,6) {
					if(l==i||l==j||l==k) sum1+=a[l];
					else sum2+=a[l];
				}
				if(sum1==sum2) {
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}