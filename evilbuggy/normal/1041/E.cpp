#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int> > vec;
	for(int i = 0; i + 1 < n; i++){
		int u, v;
		cin >> u >> v;
		vec.emplace_back(u, v);
	}
	for(int i = 0; i + 1 < n; i++){
		if(vec[i].second != n){
			cout << "NO" << '\n';
			exit(0);
		}
	}
	map<int, int> freqMap;
	for(int i = 0; i + 1 < n; i++){
		freqMap[vec[i].first]++;
		freqMap[vec[i].second]++;
	}
	int cur = 0;
	vector<int> ans(n, -1);
	for(auto x : freqMap){
		ans[cur] = x.first;
		cur += x.second;
	}
	for(int j = 0, i = 1; i <= n; i++){
		if(freqMap.count(i))continue;
		while(ans[j] != -1)j++;
		ans[j] = i;
	}
	vector<int> pref(n), suff(n);
	for(int i = 0; i < n; i++){
		pref[i] = ans[i];
		if(i)pref[i] = max(pref[i], pref[i - 1]);
	}
	for(int i = n - 1; i >= 0; i--){
		suff[i] = ans[i];
		if(i + 1 < n)suff[i] = max(suff[i], suff[i + 1]);
	}
	vector<pair<int, int> > nvec;
	for(int i = 0; i + 1 < n; i++){
		if(pref[i] < suff[i + 1]){
			nvec.emplace_back(pref[i], suff[i + 1]);
		}else{
			nvec.emplace_back(suff[i + 1], pref[i]);
		}
	}
	sort(vec.begin(), vec.end());
	sort(nvec.begin(), nvec.end());
	if(vec == nvec){
		cout << "YES" << '\n';
		for(int i = 0; i + 1 < n; i++){
			cout << ans[i] << " " << ans[i + 1] << '\n';
		}
	}else{
		cout << "NO" << '\n';
	}

	return 0;
}