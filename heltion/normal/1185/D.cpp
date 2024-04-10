//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
pair<int, int> b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	//delete 1:
	bool ok = true;
	for(int i = 3; ok and i + 1 <= n; i += 1) if(b[i + 1].first - b[i].first != b[3].first - b[2].first)
		ok = false;
	if(ok) {
		cout << b[1].second;
		return 0;
	}
	//delete 2:
	ok = true;
	for(int i = 3; ok and i + 1 <= n; i += 1) if(b[i + 1].first - b[i].first != b[3].first - b[1].first)
		ok = false;
	if(ok) {
		cout << b[2].second;
		return 0;
	}
	//else
	vector<int> v;
	for(int i = 2; i + 1 <= n; i += 1) if(b[i + 1].first - b[i].first != b[2].first - b[1].first)
		v.push_back(i);
	if(v.size() == 1){
		if(b[v[0]].first == b[v[0] + 1].first) cout << b[v[0]].second;
		else if(v[0] == n - 1) cout << b[n].second;
		else cout << -1;
		return 0;
	}
	if(v.size() == 2){
		if(v[0] + 1 == v[1] and b[v[1] + 1].first - b[v[0]].first == b[2].first - b[1].first)
			cout << b[v[1]].second;
		else cout << -1;
		return 0;
	}
	cout << -1;
	return 0;
}