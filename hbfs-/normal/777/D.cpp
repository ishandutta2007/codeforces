#include <bits/stdc++.h>
#define N 500050
using namespace std;
string s[N];
int n,m;
int ans[N];
inline int rd() { int r; scanf("%d",&r); return r; }
int main() {
	cin >> n;
	for (int i=1;i<=n;i++) cin >> s[i];
	ans[n] = s[n].size();
	for (int i=n-1;i>=1;i--) {
		bool flag = 1;
		for (int _=0;_<ans[i+1] && _<s[i].size();_++) {
			if (s[i][_] < s[i+1][_]) { ans[i] = s[i].size(); break; }
			if (s[i][_] == s[i+1][_]) ans[i] = _+1; else break; 
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<ans[i];j++) putchar(s[i][j]);
		putchar('\n');
	}
	return 0;
}