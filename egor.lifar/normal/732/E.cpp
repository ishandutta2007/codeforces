#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>
#include <unordered_map>


using namespace std;


const int MAXN = 200001;
int n, m;
int p[MAXN];
int s[MAXN];
vector<pair<int, int> > v[2 * MAXN];
unordered_map<int, vector<int> > who;
bool used[2 * MAXN];
int c, uu;
int ans[MAXN];
int cnt[MAXN];


void dfs(int u, set<pair<int, int> > &s, int &mod) {
	used[u] = 1;
	//cout << u << endl;
	if (u >= n) {
		s.insert(make_pair(0, u - n));
		mod = 0;
	} else {
		for (int i = 0; i < (int)v[u].size(); i++) {
			int h = v[u][i].first;
			if (!used[h]) {
				set<pair<int, int>> s1;
				int mod1;
				dfs(h, s1, mod1);
				mod1 += v[u][i].second;
				if (s.size() < s1.size()) {
					swap(s, s1);
					swap(mod, mod1);
				}
				for (auto x: s1) {
					s.insert(make_pair(x.first + mod1 - mod, x.second));
				} 
			}
		}
		while (!s.empty() && !who[p[u]].empty()) {
			pair<int, int> pp = *(s.begin());
			s.erase(pp);
			ans[who[p[u]].back()] = pp.second + 1;
			cnt[pp.second] += pp.first + mod;
			c++;
			uu += pp.first + mod;
			who[p[u]].pop_back();
		}
	}
}



int main() {	
	cin >> n >> m;
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		who[p[i]].push_back(i);
		vp.push_back(make_pair(p[i], i));
	}
	sort(vp.begin(), vp.end());
	for (int i = 0; i < m; i++) {
		scanf("%d", &s[i]);
		int last = n + i;
		int cnt = 0;
		while (true) {
			//cout << s[i] << endl;
			if (who.find(s[i]) != who.end()) {
				v[who[s[i]][0]].push_back(make_pair(last, cnt));
				//cout << who[s[i]][0] + 1 << ' ' << s[i] << endl;
				cnt = 0;
				last = who[s[i]][0];
			}
			if (s[i] == (s[i] + 1) >> 1) {
				break;
			}
			s[i] = (s[i] + 1) >> 1;	
			cnt++;
		} 
	}
	for (int ii = 0; ii < n; ii++) {
		int i = vp[ii].second;
		if (!used[i]) {
			int mod;
			set<pair<int, int> > s;
			dfs(i, s, mod);
		}
	}
	cout << c << ' ' << uu << endl;
	for (int i = 0; i < m; i++) {
		printf("%d ", cnt[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}