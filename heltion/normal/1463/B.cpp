#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n;
		cin >> n;
		vector<LL> v(n);
		LL sum = 0;
		for(LL& x : v) cin >> x;
		for(int i = 0; i < n; i += 1) if((i & 1)) sum += v[i]; else sum -= v[i];
		for(int i = 0; i < n; i += 1) if((i & 1) ^ (sum >= 0)) cout << "1 "; else cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}