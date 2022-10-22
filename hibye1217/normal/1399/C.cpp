#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int a[120] = {};
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a[x] += 1;
		}
		int ans = 0;
		for (int i = 1; i <= 100; i++){
			int res = 0;
			for (int j = 1; j*2 < i; j++){
				res += min(a[j], a[i-j]);
			}
			if (i % 2 == 0) res += a[i/2]/2;
			ans = max(ans, res);
		}
		cout << ans << endl;
	}
}