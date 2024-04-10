//Author: Heltion
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120;
char s[maxn], t[maxn], p[maxn];
int c[26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int q;
	for(cin >> q; q; q -= 1){
		cin >> s >> t >> p;
		int n = strlen(s), m = strlen(t);
		fill(c, c + 26, 0);
		for(int i = 0; p[i]; i += 1) c[p[i] - 'a'] += 1;
		int a = 0, b = 0, ans = 1;
		while(a <= n and b < m){
			if(s[a] == t[b]){
				a += 1;
				b += 1;
			}
			else{
				if(not c[t[b] - 'a']){
					ans = 0;
					break;
				}
				c[t[b] - 'a'] -= 1;
				b += 1;
			}
		}
		if(a != n or b != m) ans = 0;
		cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}