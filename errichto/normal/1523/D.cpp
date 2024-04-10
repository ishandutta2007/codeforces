#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, ppp;
	scanf("%d%d%d", &n, &m, &ppp);
	vector<string> in(n);
	for(string& s : in) {
		static char arr[10005];
		scanf("%s", arr);
		s = string(arr);
	}
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int best_popcount = -1;
	string answer = "not initialized";
	
	for(int rep = 0; rep < 20; ++rep) {
		int who = uniform_int_distribution<int>(0, n - 1)(rng);
		vector<int> interesting;
		for(int i = 0; i < m; ++i) {
			if(in[who][i] == '1') {
				interesting.push_back(i);
			}
		}
		int p = interesting.size();
		// coordinate compression
		vector<int> count(1 << p); // SOS dp
		for(int i = 0; i < n; ++i) {
			int mask = 0;
			for(int j = 0; j < p; ++j) {
				if(in[i][interesting[j]] == '1') {
					mask ^= (1 << j);
				}
			}
			count[mask]++;
		}
		for(int i = 0; i < p; ++i) {
			for(int mask = 0; mask < (1 << p); ++mask) {
				if(mask & (1 << i)) {
					count[mask^(1<<i)] += count[mask];
				}
			}
		}
		for(int mask = 0; mask < (1 << p); ++mask) {
			if(count[mask] >= (n + 1) / 2) {
				int popcount = __builtin_popcount(mask);
				if(popcount > best_popcount) {
					best_popcount = popcount;
					answer = string(m, '0');
					for(int i = 0; i < p; ++i) {
						if(mask & (1 << i)) {
							answer[interesting[i]] = '1';
						}
					}
				}
			}
		}
	}
	printf("%s\n", answer.c_str());
}