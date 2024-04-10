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
		int arr[120] = {};
		int n, mn = 120, mx = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			arr[x] += 1;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		bool chk = true;
		for (int i = mn; i <= mx; i++) chk = chk && arr[i];
		cout << (chk ? "YES" : "NO") << endl;
	}
}