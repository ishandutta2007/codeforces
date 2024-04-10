#include<bits/stdc++.h>

using namespace std;

vector<int> res;
multiset<int> occ; //count number of occurrences
map<int, int> wrap; // wrapper for each value
vector<int> vals; // unwrapped values

void finish(int a, int b) {
	res.push_back(a);
	res.push_back(b);
	res.push_back(a);
	res.push_back(b);
	occ.clear();
	wrap.clear();
	vals.clear();
}

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int v; cin >> v;
		if(wrap.count(v)) {
			finish(wrap[v], v);
			continue;
		} else {
			if(occ.count(v)) {
				int cnt = (occ.count(v) >= 2) ? 1 : 0; 
				while(cnt || vals.back() != v) {
					if(vals.back() == v) cnt--;
					wrap[vals.back()] = v;
					vals.pop_back();
				}
			}
			occ.insert(v);
			vals.push_back(v);
		}
	}
	cout << res.size() << '\n';
	for(int i : res) cout << i << ' '; cout << '\n';
}