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

int main() {
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	ll c=n/k;
	if(c%2==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}