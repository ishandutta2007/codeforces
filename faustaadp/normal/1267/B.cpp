#include <bits/stdc++.h>

#define lli long long int
#define ii pair<int, int>
#define ll pair<lli, lli>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int len;
	char s[300005];
	vector<pair<char, int> > v;
	pair<char, int> u;
	scanf("%s", s);
	len = strlen(s);
	v.pb(mp(s[0], 1));
	for (int i = 1; i < len; i++)
		if (s[i] != s[i - 1])
			v.pb(mp(s[i], 1));
		else {
			u = v.back();
			v.pop_back();
			v.pb(mp(u.fi, u.se + 1));
		}
	if ((int) v.size() % 2 == 0) {
		puts("0");
		return 0;
	}
	len = v.size();
	for (int i = 0; i < (len / 2); i++) {
		if (v[i].fi != v[len - 1 - i].fi) {
			puts("0");
			return 0;
		}
	}
	for (int i = 0; i < (len / 2); i++) {
		if (v[i].se + v[len - 1 - i].se < 3) {
			puts("0");
			return 0;
		}
	}
	if (v[len / 2].se < 2) {
		puts("0");
	}
	else {
		printf("%d\n", v[len / 2].se + 1);
	}
	return 0;
}