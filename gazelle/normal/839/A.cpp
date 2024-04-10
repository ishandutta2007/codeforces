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
#include<complex>

#define INF (long long)1000000000
#define MOD 1000000007
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	int n,k;
	cin>>n>>k;
	int c=0;
	int st=0;
	int res = -1;
	REP(i,n) {
		int a;
		cin>>a;
		st+=a;
		c+=min(st,8);
		st-=min(st,8);
		if(c>=k) {
			res=i+1;
			break;
		}
	}
	if(res!=-1) cout<<res<<endl;
	else cout<<-1<<endl;
}