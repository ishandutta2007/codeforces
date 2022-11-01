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
#define rep(i,m) for(long long i=0; i<m; ++i)
#define repp(i,n,m) for(long long i=n; i<m; ++i)
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vi a(n);
	rep(i,n) cin>>a[i];
	if(n%2==1&&a[0]%2==1&&a[n-1]%2==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}