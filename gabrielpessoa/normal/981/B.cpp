#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1e5+5;

map<int, ll> gold;
ll a[ms], x[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	for(int i = 0; i < 2; i++) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> x[i];
			gold[a[i]] = max(gold[a[i]], x[i]);
		}
	}
	ll ans = 0;
	for(auto i : gold) {
		ans += i.second;
	}
	cout << ans << endl;
	return 0;
}