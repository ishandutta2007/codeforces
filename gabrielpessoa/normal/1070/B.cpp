#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

set<ui> wl[33];
set<ui> forb[33];
set<pair<ui, ui>> ans;
ui blacks[ms];
int blackId[ms];
int z = 0;

void converter(ui k) {
	cout << (k >> 24) << "." << ((k << 8) >> 24)  << "." << ((k << 16) >> 24)  << "." <<  ((k << 24) >> 24);
}

pair<ui, int> valueOf(string s) {
	s = s.substr(1);
	replace(s.begin(), s.end(), '.', ' ');
	replace(s.begin(), s.end(), '/', ' ');
	stringstream ss(s);
	int k = 24;
	ui x = 0;
	ui y = 0;
	while(k >= 0) {
		ss >> y;
		x += y << k;
		k -= 8;	
	}
	int w = 32;
	if(!(ss >> w)) w = 32;
	//cout << "saindo daqui " << x << ' ' << w << endl;
	return make_pair(x, w);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout << converter(-1) << endl;
	//cout << valueOf("-255.255.255.255") + 1<< endl;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		auto p = valueOf(s);
		ui x = p.first;
		int kb = p.second;
		if(s[0] == '-') {
			blackId[z] = kb;
			blacks[z++] = x;
		} else {
			for(int k = 0; k < kb; k++) {
				if(!k) {
					wl[k].insert(0);
					continue;
				}
				int bu = 32 - k;
				ui y = ((x >> bu) << bu);
				//cout << "invalid " << x << ' ' << k << ' ' << y << endl;
				wl[k].insert(y);
			}
			int bu = 32 - kb;
			ui y = ((x >> bu) << bu);
			forb[kb].insert(y);
		}
	}
	for(int i = 0; i < z; i++) {
		for(int k = 0; k < 34; k++) {
			if(k > blackId[i]) {
				cout << -1 << '\n';
				return 0;
			}
			int bu = 32 - k;
			ui y = k ? ((blacks[i] >> bu) << bu) : 0;
			if(forb[k].count(y)) {
				cout << -1 << '\n';
				return 0;
			}
			if(!wl[k].count(y)) {
				ans.insert({y, k});
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto p : ans) {
		converter(p.first);
		cout << "/" << p.second << '\n';
	}
}