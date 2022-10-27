#include <bits/stdc++.h>
using namespace std;

const int maxN = 5005;

int f[maxN], a[maxN][maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;

	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		int cur = 0;
		for(int j = 1; j <= m; j++){
			if(s[j - 1] != '0'){
				cur++;
			}else{
				cur = 0;
			}
			a[i][j] = cur;
		}
	}
	int ans = 0;
	for(int j = 1; j <= m; j++){
		for(int i = 0; i <= m; i++){
			f[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			f[a[i][j]]++;
		}
		int cnt = n - f[0];
		for(int i = 1; i <= m; i++){
			ans = max(ans, i*cnt);
			cnt -= f[i];
		}
	}
	cout << ans << '\n';

	return 0;
}