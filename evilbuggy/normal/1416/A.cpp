#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int last[N], ans[N], maxs[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			maxs[i] = 0;
			last[i] = 0;
			ans[i] = n + 1;
		}
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			maxs[x] = max(maxs[x], i - last[x]);
			last[x] = i;
		}
		for(int i = 1; i <= n; i++){
			maxs[i] = max(maxs[i], n + 1 - last[i]);
		}
		for(int i = 1; i <= n; i++){
			ans[maxs[i]] = min(ans[maxs[i]], i);
		}
		for(int i = 2; i <= n; i++){
			ans[i] = min(ans[i], ans[i - 1]);
		}
		for(int i = 1; i <= n; i++){
			if(ans[i] == n + 1)ans[i] = -1;
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}