#include <bits/stdc++.h>
using namespace std;

const int maxn = 100*1000 + 5;

long long cnt[maxn], sum[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int> > a(n);
	for(int i = 0; i < n; i++){
		a[i].resize(m);
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	long long ans = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans += cnt[a[i][j]]*i - sum[a[i][j]];
		}
		for(int j = 0; j < m; j++){
			cnt[a[i][j]]++;
			sum[a[i][j]] += i;
		}
	}
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			ans += cnt[a[i][j]]*j - sum[a[i][j]];
		}
		for(int i = 0; i < n; i++){
			cnt[a[i][j]]++;
			sum[a[i][j]] += j;
		}
	}
	cout << ans << '\n';

	return 0;
}