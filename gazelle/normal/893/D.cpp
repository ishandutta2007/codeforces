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
	ll n,d;
	cin>>n>>d;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> b(n,0);
	b[0]=a[0];
	FOR(i,1,n) b[i]=b[i-1]+a[i];
	REP(i,n) if(b[i]>d) {
		cout<<-1<<endl;
		return 0;
	}
	vector<ll> c(n);
	c[n-1]=d-b[n-1];
	for(ll i=n-2; i>=0; i--) c[i]=min(d-b[i],c[i+1]);
	ll ret=0;
	ll buf=0;
	REP(i,n) {
		if(a[i]==0) {
			if(b[i]+buf<0) {
				ret++;
				buf+=c[i]-buf;
				if(b[i]+buf<0) {
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<ret<<endl;
}