#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int k = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++){
		a[i].first = nxt();
		a[i].second = nxt();
	}

	vector<pair<int, int>> ev;
	for (int i = 0; i < n; i++){
		ev.push_back({i, -1});
		ev.push_back({i, 0});
	}

	sort(all(ev), [&](const pair<int, int>& p, const pair<int, int>& q){
		return a[p.first].first + k * p.second < 
			   a[q.first].first + k * q.second;
	});

	vector<int> pos;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= k; j++){
			pos.push_back(a[i].second - j);
		}
	}
	sort(all(pos));
	pos.resize(unique(all(pos)) - pos.begin());

	vector<int> ptr;
	for (int i = 0; i < n; i++){
		ptr.push_back(lower_bound(all(pos), a[i].second - k) - pos.begin());
	}

	vector<long long> ans(n + 1);
	int sz = pos.size();
	vector<int> lst(sz, a[ev[0].first].first - k);
	// vector<int> cur(sz, 0);
	pos.assign(sz, 0);
	for (auto e : ev){
		// cerr << e.first << " " << e.second << "\n";
		int l = ptr[e.first];
		int ps = a[e.first].first + k * e.second;
		for (int i = l; i < l + k; i++){
			// cerr << i << ": " << lst[cur[i]]
			ans[pos[i]] += ps - lst[i];
			lst[i] = ps;
			pos[i] -= 2 * e.second + 1;
		}
	}

	cout.sync_with_stdio(0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}