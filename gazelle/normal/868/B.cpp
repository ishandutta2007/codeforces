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
	ll h,m,s,t1,t2;
	cin>>h>>m>>s>>t1>>t2;
	if(h==12) h=0;
	if(t1==12) t1=0;
	if(t2==12) t2=0;
	if(t1>t2) swap(t1,t2);
	if(t1<=h&&t2>h&&t1*5<=m&&t2*5>m&&t1*5<=s&&t2*5>=s) {
		cout<<"YES"<<endl;
		return 0;
	}
	if(!(t1<=h&&t2>h)&&!(t1*5<=m&&t2*5>m)&&!(t1*5<=s&&t2*5>=s)) {
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
}