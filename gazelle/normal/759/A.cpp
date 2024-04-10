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
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
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
	ll n;
	cin>>n;
	vector<ll> p(n);
	REP(i,n) cin>>p[i];
	vector<ll> b(n);
	REP(i,n) cin>>b[i];
	ll cnt=0;
	REP(i,n) {
		if(b[i]==1) cnt++;
	}
	ll ans=0;
	if(cnt%2==0) ans++;
	vector<bool> used(n,false);
	ll cnct=0;
	REP(i,n) {
		if(!used[i]) {
			cnct++;
			ll q=i;
			while(!used[q]) {
				used[q]=true;
				q=p[q]-1;
			}
		}
	}
	if(cnct==1) cout<<ans<<endl;
	else cout<<ans+cnct<<endl;
}