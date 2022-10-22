#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v[100001];
vector<int> a, b, c;
int e[100001];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i){
		int u, w;
		scanf("%d %d", &u, &w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for (int i = 1; i <= n; ++i) sort(v[i].begin(), v[i].end());
	int cnt=0;
	for (int i = 1; i <= n; ++i){
		if (cnt == 0){
			int l = v[i].size();
			for (int j = 0; j < l; ++j) a.push_back(v[i].at(j));
			++cnt;
			e[i] = 1;
			continue;
		}
		if (cnt == 1 && v[i] != a){
			int l = v[i].size();
			for (int j = 0; j < l; ++j) b.push_back(v[i].at(j));
			++cnt;
			e[i] = 2;
			continue;
		}
		if (cnt == 2 && v[i] != a && v[i] != b){
			int l = v[i].size();
			for (int j = 0; j < l; ++j) c.push_back(v[i].at(j));
			++cnt;
			e[i] = 3;
			continue;
		}
		if (cnt == 3 && v[i] != a && v[i] != b && v[i] != c){
			printf("-1");
			return 0;
		}
		if (v[i] == a) e[i] = 1;
		if (v[i] == b) e[i] = 2;
		if (v[i] == c) e[i] = 3;
	}
	if (cnt == 3) for (int i = 1; i <= n; ++i) printf("%d ", e[i]);
	else printf("-1");
}