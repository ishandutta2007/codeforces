#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll compute(array<ll, 2> st, array<ll, 2> en){
	ll dx = en[0] - st[0];
	ll dy = en[1] - st[1];
	ll a = dx - dy, b = dy;
	assert(a >= 0 && b >= 0);
	int flg = (st[0] + st[1])&1;
	if(flg&1){
		return (a + 1)/2;
	}else{
		if(a == 0){
			return b;
		}else{
			return a/2;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<array<ll, 2> > pt(n);
		for(auto &x : pt){
			cin >> x[0];
		}
		for(auto &x : pt){
			cin >> x[1];
		}
		sort(pt.begin(), pt.end());
		ll ans = compute(array<ll, 2>({1, 1}), pt[0]);
		for(int i = 1; i < n; i++){
			ans += compute(pt[i - 1], pt[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}