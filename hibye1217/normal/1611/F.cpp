#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define fr first
#define sc second
using pl2 = pair<ll, ll>;

// #define DEBUG

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ed = 1; ll sum = 0;
		ll mn = 1e15, cut = -k;
		pl2 ans = {-1, -1};
		for (int st = 1; st <= n; st++){
			if (ed <= st){
				ed = st; sum = 0;
				cut = -k; mn = 1e15;
			}
			if (mn < cut){ goto next; }
			mn = cut;
			while (ed <= n){
				if (sum+arr[ed] >= cut){ sum += arr[ed]; ed += 1; }
				else{ break; }
			}
			//cout << "P " << cut << ' ' << st << ' ' << ed << endl;
			if (ed-st > ans.sc-ans.fr){ ans = {st, ed}; }
			next: cut += arr[st];
		}
		if (ans.fr == -1){ cout << -1 << endl; }
		else{ cout << ans.fr << ' ' << ans.sc-1 << endl; }
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