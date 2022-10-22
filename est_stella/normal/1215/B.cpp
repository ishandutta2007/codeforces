#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n;
int a[200010];
ll p, ne;

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] /= abs(a[i]);
	}

	ll mul = 1;
	ll pos = 0, neg = 0;
	for(int i=1; i<=n; i++) {
		mul *= a[i];
		if(mul > 0) pos++;
		else neg++;
	}
	p += pos;
	ne += neg;

	//cout << pos << " " << neg << endl;

	for(int i=2; i<=n; i++) {
		if(a[i-1] > 0) {
			pos--;
		}
		else {
			neg--;
			swap(pos, neg);
		}

		p += pos;
		ne += neg;
		//cout << pos << " " << neg << endl;
	}

	cout << ne << " " << p;
}