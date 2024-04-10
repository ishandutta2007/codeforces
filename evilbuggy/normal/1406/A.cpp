#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;

int f[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++){
			int x; cin >> x; f[x]++;
		}
		int ans = 0, prev = 2;
		for(int i = 0; i < maxN; i++){
			prev = min(prev, f[i]);
			ans += prev;
		}
		cout << ans << '\n';
	}

	return 0;
}