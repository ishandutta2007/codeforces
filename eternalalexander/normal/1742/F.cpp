#include <bits/stdc++.h>
using ll = long long;
int q;
ll s[105],t[105];
char str[1000005];

int answer() {
	// s min min ... max
	// t max max ... min
	int smin = -1, tmax = -1;
	for (int i = 0; i < 26; ++ i) if (s[i]) { smin = i; break; }
	for (int i = 25; i >= 0; i --) if (t[i]) { tmax = i; break; }
	if (tmax != 0) return 1;
	assert(smin == 0);
	ll c = std::min(s[smin],t[tmax]);
	s[smin] -= c;
	t[tmax] -= c;
	int c1 = -1, c2 = -1;
	for (int i = 0; i < 26; ++ i) if (s[i]) { c1 = i; break; }
	for (int i = 25; i >= 0; i --) if (t[i]) { c2 = i; break; }
	int res = c1 < c2;
	s[smin] += c;
	t[tmax] += c;
	return res;
}

void solve() {
	scanf("%d",&q);
	for (int i = 0; i < 26; ++ i) s[i] = t[i] = 0;
	s[0] = t[0] = 1;
	while (q --) {
		int d,k;
		scanf("%d%d%s",&d,&k,str + 1);
		int m = std::strlen(str + 1);
		for (int i = 1; i <= m; ++ i) {
			if (d == 1) s[str[i] - 'a'] += k;
			else t[str[i] - 'a'] += k;
		} 
		if (answer()) puts("YES");
		else puts("NO");
	} 
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}