#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
int n,d,m;
vi a, b;
vector<ll>sum;

int main() {_
	cin >> n >> d >> m;
	for(int x,i=1; i<=n; ++i) {
		cin >> x;
		if(x <= m) a.PB(x);
		else b.PB(x);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	sum.PB(0);
	for(int x : a) {
		sum.PB(sum.back() + x);
	}
	//b.PB(0);
	ll s = 0;
	ll ans = sum.back();
	//~ for(ll x : sum) cout << x << "\n";
	for(int i = 1; i <= (int)b.size(); ++i) {
		s += b[(int)b.size() - i];
		//cout << s << "\n";
		//block = i * d;
		//b.size() - i
		if((int)b.size() - i >= (ll)(i - 1) * d) {
			ans = max(ans, s + sum.back());
		} else {
			ll rem = (ll)(i - 1) * d - ((int)b.size() - i);
			//rem 
			if(rem <= (int)a.size()) {
				ans = max(ans, s + sum[(int)sum.size() - rem - 1]);
			}
		}
	}
	cout << ans;
		
	
}