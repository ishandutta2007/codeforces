#include<bits/stdc++.h>
using namespace std;

typedef pair<bool, int> player;
set<player> red;
set<player> yellow;

int main() {
	string h, a; cin >> h >> a;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		char c; int v; char r;
		cin >> t >> c >> v >> r;
		player p(c == 'h', v);
		if(red.count(p)) continue;
		else if(yellow.count(p) || r == 'r') {
			cout << (c == 'h' ? h : a) << ' ' << v << ' ' << t << '\n';
			red.insert(p);
		} else yellow.insert(p);
	}
	return 0;
}