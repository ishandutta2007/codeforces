#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		ll n, d;
		cin >> n >> d;
		cout << (4*(d-1) <= n*n || 4*d <= n*n + 2*n + 1 ? "YES" : "NO") << endl;
	}
}