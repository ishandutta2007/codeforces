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
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string pass;
	cin>>pass;
	ll n;
	cin>>n;
	vector<ll> a(26,0);
	vector<ll> b(26,0);
	REP(i,n) {
		string s;
		cin>>s;
		if(s==pass) {
			cout<<"YES"<<endl;
			return 0;
		}
		a[s[0]-'a']++;
		b[s[s.size()-1]-'a']++;
	}
	if(a[pass[1]-'a']!=0&&b[pass[0]-'a']!=0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}