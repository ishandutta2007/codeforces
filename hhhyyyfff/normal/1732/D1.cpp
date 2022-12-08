#include <bits/stdc++.h>

using namespace std;

char o[200001][2];
map<long long, long long> hd;
map<long long, vector<long long>> mp;
map<long long, set<long long>> lack;
set<long long> st;
int q;
long long x[200001];

int main() {
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%s%lld", o[i], &x[i]);
		if (o[i][0] == '?')
			if (!hd[x[i]]) {
				hd[x[i]] = x[i];
				mp[x[i]].push_back(x[i]);
			}
	}
	for (int i = 1; i <= q; ++i)
		if (o[i][0] == '+') {
			st.insert(x[i]);
			for (long long j : mp[x[i]]) {
				if (hd[j] == x[i]) {
					while (st.find(hd[j]) != st.end())
						mp[hd[j] += j].push_back(j);
				} else lack[j].erase(x[i]);
			}
		} else if (o[i][0] == '-') {
			st.erase(x[i]);
			for (long long j : mp[x[i]])
				lack[j].insert(x[i]);
		} else printf("%lld\n", lack[x[i]].empty() ? hd[x[i]] :
				*lack[x[i]].begin());
	return 0;
}