#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;

int main() {
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		string a, b; cin >> a >> b;
		if(!mp.count(a)) {
			mp[a] = a;
		}
		mp[b] = mp[a];
		mp.erase(a);
	}
	cout << mp.size() << '\n';
	for(auto it : mp) {
		cout << it.second << ' ' << it.first << '\n';
	}
	return 0;
}