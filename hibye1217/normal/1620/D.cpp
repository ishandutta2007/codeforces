#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

// #define DEBUG

ll arr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		ll ans = 1e15;
		for (int a = 0; a <= 2; a++){
			for (int b = 0; b <= 3; b++){
				ll res = 0;
				vector<int> v;
				for (int a1 = 0; a1 <= a; a1++){
					for (int b1 = 0; b1 <= b; b1++){
						v.push_back(a1 + 2*b1);
					}
				}
				bool flg = 1;
				for (int i = 1; i <= n; i++){
					bool chk = 0;
					ll val = 1e15;
					for (int x : v){
						if ( arr[i] < x || (arr[i]-x)%3 != 0 ){ continue; }
						chk = 1; ll num = (arr[i]-x)/3;
						val = min(val, num+a+b);
					}
					res = max(res, val);
					flg &= chk;
				}
				if (!flg){ continue; }
				//cout << "P " << a << ' ' << b << ' ' << res-a-b << endl;
				ans = min(ans, res);
			}
		}
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}