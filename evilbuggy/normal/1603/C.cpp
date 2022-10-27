#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
const int mod = 998244353;

int a[maxN], fl[maxN], ce[maxN], k[maxN];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int sum = 0, ans = 0, tri = 0;
	for(int i = 1; i <= n; i++){
		k[i] = 1;
		add(sum, i);
		fl[i] = ce[i] = a[i];
		for(int j = i - 1; j >= 1; j--){
			if(ce[j] <= fl[j + 1])break;
			
			add(sum, mod - (k[j]*1LL*j%mod));
			k[j] = (a[j] + fl[j + 1] - 1)/fl[j + 1];
			fl[j] = a[j]/k[j];
			ce[j] = (a[j] + k[j] - 1)/k[j];
			add(sum, k[j]*1LL*j%mod);
		}
		add(tri, i);
		add(ans, sum);
		add(ans, mod - tri);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}