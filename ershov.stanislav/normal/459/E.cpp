#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=333333;
#else
const int maxn=333;
#endif

int n, m, maxl[maxn], ans;
vector<pair<int, pair<int, int> > > e;
vector<pair<int, int> > change;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m;
	e.resize(m);
	for (int i=0; i<m; i++) scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
	sort(e.begin(), e.end());
	for (int i=(int)e.size()-1, prev=-1; i>=0; i--) {
		if (e[i].first!=prev) {
			for (int j=0; j<change.size(); j++) maxl[change[j].first]=max(maxl[change[j].first], change[j].second);
			change.clear();
		}
		change.push_back(make_pair(e[i].second.first, maxl[e[i].second.second]+1));
		prev=e[i].first;
	}
	for (int j=0; j<change.size(); j++) maxl[change[j].first]=max(maxl[change[j].first], change[j].second);
	change.clear();
	for (int i=1; i<=n; i++) ans=max(ans, maxl[i]);
	cout << ans;
	return 0;
}