#include <bits/stdc++.h>
using namespace std;

inline void update(int i, int x, int n, vector<int> &f){
	while(i <= n){
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i, vector<int> &f){
	int ret = 0;
	while(i){
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		long long ans = 0;
		vector<int> f(n + 1);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			ans += i - query(x - 1, f);
			update(x, 1, n, f);
		}
		cout << ans << '\n';
	}

	return 0;
}