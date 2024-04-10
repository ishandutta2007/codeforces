#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;          
	vector<vector<int>> trie(1, vector<int>(2, -1));
	vector<int> emp(2, -1), ct(1);
	auto add = [&](int n) {
		int cur = 0;
		bitset<31> bs(n);
		for (int i = 30; i >= 0; --i) {
			if (trie[cur][bs[i]] == -1) {
				trie[cur][bs[i]] = trie.size();
				trie.push_back(emp);
				ct.push_back(0);	
			}
			cur = trie[cur][bs[i]];
			++ct[cur];		
		}			
	};
	add(0);
	while (q--) {
		char c;
		int n;
		cin >> c >> n;
		if (c == '+') {
			add(n);
		} else if (c == '-') {
			int cur = 0;
			bitset<31> bs(n);
			for (int i = 30; i >= 0; --i) {
				cur = trie[cur][bs[i]];
				--ct[cur];		
			}			
		} else {
			bitset<31> bs(n);
			int cur = 0;
			for (int i = 30; i >= 0; --i) {
				//cerr << cur << '\n';
				int ex = bs[i] ^ (trie[cur][bs[i]^1] != -1 && ct[trie[cur][bs[i]^1]]);
				n ^= ex<<i;
				cur = trie[cur][ex];
			}
			cout << n << '\n';
		}
	}
}