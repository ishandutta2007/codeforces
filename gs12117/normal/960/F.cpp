#include<cstdio>
#include<map>
int n, m;
struct edge {
	int a, b, c;
	bool operator<(const edge& r)const {
		return c < r.c;
	}
};
edge el[100100];
std::map<int, int> mp[100100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &el[i].a, &el[i].b, &el[i].c);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a = el[i].a;
		int b = el[i].b;
		int c = el[i].c;
		std::map<int, int>::iterator ite = mp[a].lower_bound(c);
		int v;
		if (ite == mp[a].begin()) {
			v = 1;
		}
		else {
			ite--;
			v = (ite->second) + 1;
		}
		ite = mp[b].upper_bound(c);
		if (ite != mp[b].begin()) {
			ite--;
			if ((ite->second) >= v)continue;
		}
		mp[b][c] = v;
		if (ans < v)ans = v;
		while (1) {
			ite = mp[b].find(c);
			ite++;
			if (ite == mp[b].end())break;
			if ((ite->second) > v)break;
			mp[b].erase(ite);
		}
	}
	printf("%d", ans);
	return 0;
}