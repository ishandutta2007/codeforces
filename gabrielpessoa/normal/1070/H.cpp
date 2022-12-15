#include <bits/stdc++.h>
using namespace std;

map< string, set<string> > cnt;

void add(string &s){
	string x;
	for(int i = 0; i < s.size(); i++){
		for(int j = i; j < s.size(); j++){
			x.push_back(s[j]);
			cnt[x].insert(s);
		}
		x.clear();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		add(s);
	}
	cin >> q;
	while(q--){
		cin >> s;
		int ans = cnt[s].size();
		cout << ans << " ";
		if(ans) cout << (*cnt[s].begin()) << endl;
		else cout << "-" << endl;
	}
}