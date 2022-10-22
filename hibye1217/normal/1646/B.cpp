#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		sort(arr+1, arr+n+1);
		int p1 = 2, p2 = n;
		ll s1 = arr[1] + arr[2], s2 = arr[n];
		bool ans = 0;
		while (p1 < p2){
			if (s1 < s2){ ans = 1; break; }
			p1 += 1; p2 -= 1;
			if (p1 >= p2){ break; }
			s1 += arr[p1]; s2 += arr[p2];
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}