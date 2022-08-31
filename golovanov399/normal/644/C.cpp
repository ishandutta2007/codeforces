#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

int main(){

	cin.sync_with_stdio(0);
	int n = nxt();
	vector<string> hosts;
	vector<string> queries(n);
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		s += '/';
		s = queries[i] = s.substr(7);
		hosts.push_back(s.substr(0, s.find('/')));
	}

	sort(all(hosts));
	hosts.resize(unique(all(hosts)) - hosts.begin());
	int sz = hosts.size();
	vector<vector<string>> paths(sz);

	for (string query : queries){
		string host = query.substr(0, query.find('/'));
		int pos = lower_bound(all(hosts), host) - hosts.begin();

		string path = query.substr(query.find('/'));
		paths[pos].push_back(path);
	}

	for (auto& v : paths){
		sort(all(v));
		v.resize(unique(all(v)) - v.begin());
	}

	vector<int> ans(sz);
	for (int i = 0; i < sz; i++)
		ans[i] = i;
	sort(all(ans), [&](int x, int y){
		return paths[x] < paths[y];
	});

	vector<vector<int>> toout;
	for (int i = 0; i < sz;){
		int j = i;
		while (i < sz && paths[ans[i]] == paths[ans[j]])
			i++;
		if (i > j + 1){
			toout.emplace_back();
			for (int ij = j; ij < i; ij++)
				toout.back().push_back(ans[ij]);
		}
	}

	cout.sync_with_stdio(0);
	cout << toout.size() << "\n";
	for (const auto& v : toout){
		for (int x : v){
			cout << "http://" + hosts[x] << " ";
		}
		cout << "\n";
	}

	return 0;
}