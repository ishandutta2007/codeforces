#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

ll arr[100020];

void Main(){
	int t; cin >> t; while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++){ cin >> arr[i]; }
		sort(arr+1, arr+m+1);
		for (int i = m; i >= 1; i--){ arr[i] -= arr[1]; arr[i] += 1; }
		arr[m+1] = n+1;
		vector<pl2> v;
		for (int i = 1; i <= m; i++){
			if (arr[i]+1 <= arr[i+1]-1){ v.push_back({ arr[i]+1, arr[i+1]-1 }); }
		}
		sort(all(v), [](pl2 a, pl2 b){ return a.sc-a.fr > b.sc-b.fr; });
		ll ans = 0, dif = 0;
		for (pl2 p : v){
			ll res = p.sc-p.fr + 1;
			//cout << "P " << p.fr << ' ' << p.sc << "   " << res << ' ' << dif << ' ' << ans << endl;
			res -= 2*dif;
			if (res > 0){ ans += 1; res -= 2; dif += 1; }
			//cout << "P " << p.fr << ' ' << p.sc << "   " << res << ' ' << dif << ' ' << ans << endl;
			if (res > 0){ ans += res; dif += 1; }
		}
		cout << n-ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}