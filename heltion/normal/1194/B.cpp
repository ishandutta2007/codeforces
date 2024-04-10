//Author: Heltion
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
char s[maxn];
int r[maxn], c[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int q;
	for(cin >> q; q; q -= 1){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i += 1) cin >> (s + i * m);
		for(int i = 0; i < n; i += 1) r[i] = 0;
		for(int j = 0; j < m; j += 1) c[j] = 0;
		for(int i = 0; i < n; i += 1)
			for(int j = 0; j < m; j += 1)
				if(s[i * m + j] == '*'){
					r[i] += 1;
					c[j] += 1;
				}
		int ans = n + m - 1;
		for(int i = 0; i < n; i += 1)
			for(int j = 0; j < m; j += 1)
				ans = min(ans, (m - r[i]) + (n - c[j]) - (s[i * m + j] == '.'));
		cout << ans << "\n";
	}	
	return 0;
}