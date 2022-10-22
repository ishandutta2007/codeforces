#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int a[100005];

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int minval = 2e9;
	rep(i,0,n){
		cin >> a[i];
		minval = min(minval, a[i]);
	}
	ll ans = 0;
	rep(i,0,n){
		if((a[i]-minval)%k){
			cout << "-1" << endl;
			return 0;
		}
		ans += (a[i]-minval)/k;
	}
	cout << ans << endl;
}