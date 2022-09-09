//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 540000;
char s[maxn];
int a[26][maxn], p[26][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n >> (s + 1);
	for(int i = 1; i <= n; i += 1){
		for(int j = 0; j < 26; j += 1) a[j][i] += a[j][i - 1];
		a[s[i] - 'a'][i] += 1;
		p[s[i] - 'a'][a[s[i] - 'a'][i]] = i;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i += 1){
		string t;
		cin >> t;
		int b[26] = {0};
		for(char c : t) b[c - 'a'] += 1;
		int ans = 0;
		for(int i = 0; i < 26; i += 1) ans = max(ans, p[i][b[i]]);
		cout << ans << "\n";
	}
	return 0;
}