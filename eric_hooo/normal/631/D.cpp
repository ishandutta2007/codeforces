#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <char, long long> pci;

pci s[200010], t[200010];
int fail[200010];
int n, m;

void getfail(){
	int j = -1;
	fail[1] = -1;
	for (int i = 2; i <= n - 1; i++){
		while (~j && s[j] != s[i - 1]) j = fail[j];
		j = j == -1 ? 1 : j + 1, fail[i] = j;
		if (i != n - 1 && s[i] == s[fail[i]] && fail[fail[i]] != -1) fail[i] = fail[fail[i]];
	}
}

int main(){
	scanf("%d%d", &m, &n);
	int tot = 0;
	for (int i = 0; i < m; i++){
		pci tmp; scanf("%I64d-%c", &tmp.se, &tmp.fi);
		if (!tot) t[tot++] = tmp;
		else if (t[tot - 1].fi != tmp.fi) t[tot++] = tmp;
		else t[tot - 1].se += tmp.se;
	}
	m = tot, tot = 0;
	for (int i = 0; i < n; i++){
		pci tmp; scanf("%I64d-%c", &tmp.se, &tmp.fi);
		if (!tot) s[tot++] = tmp;
		else if (s[tot - 1].fi != tmp.fi) s[tot++] = tmp;
		else s[tot - 1].se += tmp.se;
	}
	n = tot;
	if (n == 1){
		long long ans = 0;
		for (int i = 0; i < m; i++){
			if (t[i].fi == s[0].fi && t[i].se >= s[0].se) ans += t[i].se - s[0].se + 1;
		}
		printf("%I64d\n", ans);
	} else if (n == 2){
		long long ans = 0;
		for (int i = 1; i < m; i++){
			if (t[i - 1].fi == s[0].fi && t[i].fi == s[1].fi)
				if (t[i - 1].se >= s[0].se && t[i].se >= s[1].se) ans++;
		}
		printf("%I64d\n", ans);
	} else {
		getfail();
		long long ans = 0;
		int j = 1;
		for (int i = 0; i < m; i++){
			while (~j && t[i] != s[j]) j = fail[j];
			j = j == -1 ? 1 : j + 1;
			if (j == n - 1){
				if (i - n + 2 >= 0 && t[i - n + 2].fi == s[0].fi && t[i - n + 2].se >= s[0].se)
					if (i + 1 < m && t[i + 1].fi == s[n - 1].fi && t[i + 1].se >= s[n - 1].se) ans++;
				j = fail[j];
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}