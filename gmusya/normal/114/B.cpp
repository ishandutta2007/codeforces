#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <string> a(n);
	vector <int> answer;
	map <string, int> ma;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma[a[i]] = i;
	}
	vector <pair <int, int>> b(m);
	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		b[i] = { ma[s], ma[t] };
	}
	for (int i = 0; i < (1 << n); i++) {
		vector <bool> used(n);
		int copy_i = i;
		for (int j = 0; j < n; j++) {
			used[j] = (copy_i % 2);
			copy_i /= 2;
		}
		bool tf = true;
		for (int j = 0; j < m; j++) 
			if (used[b[j].first] && used[b[j].second])
				tf = false;
		if (!tf)
			continue;
		int cnt = 0;
		for (int j = 0; j < n; j++)
			cnt += used[j];
		if (cnt > answer.size()) {
			answer.resize(0);
			for (int j = 0; j < n; j++)
				if (used[j])
					answer.push_back(j);
		}
	}
	vector <string> ans(answer.size());
	for (int i = 0; i < answer.size(); i++)
		ans[i] = a[answer[i]];
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto now : ans)
		cout << now << endl;
	return 0;
}