#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	vector<int> b(n);
	map<int,int> initial_freq;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		++initial_freq[b[i]];
	}
	// (freq, value)
	set<pair<int,int>> s;
	for(pair<int,int> p : initial_freq) {
		s.insert({p.second, p.first});
	}
	vector<pair<int,int>> mapping;
	// 1) full matches
	for(int rep = 0; rep < x; ++rep) {
		auto it = prev(s.end()); // last element
		int freq = it->first;
		int value = it->second;
		mapping.emplace_back(value, value);
		s.erase(it);
		--freq;
		if(freq != 0) {
			s.insert({freq, value});
		}
	}
	// 2) partial matches
	while((int) s.size() >= 2) {
		if(n - (int) mapping.size() == 3 && (int) s.size() == 3) {
			// 1 2 3 -> 2 3 1
			vector<int> triple;
			for(pair<int,int> p : s) {
				assert(p.first == 1);
				triple.push_back(p.second);
			}
			assert((int) triple.size() == 3);
			for(int i = 0; i < 3; ++i) {
				int j = (i + 1) % 3;
				mapping.emplace_back(triple[i], triple[j]);
			}
			break;
		}
		auto it = prev(s.end());
		int freq = it->first;
		int value = it->second;
		s.erase(it);
		it = prev(s.end());
		int freq2 = it->first;
		int value2 = it->second;
		s.erase(it);
		mapping.emplace_back(value, value2);
		mapping.emplace_back(value2, value);
		if(freq != 1) {
			s.insert({freq - 1, value});
		}
		if(freq2 != 1) {
			s.insert({freq2 - 1, value2});
		}
	}
	
	vector<vector<int>> remaining(n + 2);
	for(pair<int,int> p : mapping) {
		remaining[p.first].push_back(p.second);
	}
	// find non-existing value
	vector<bool> existing(n + 3);
	for(int a : b) {
		existing[a] = true;
	}
	int nope = 1;
	while(existing[nope]) {
		nope++;
	}
	assert(nope <= n + 1);
	
	
	vector<int> answer;
	int count_nopes = 0;
	// puts("YES");
	for(int a : b) {
		if(remaining[a].empty()) {
			count_nopes++;
			answer.push_back(nope);
			// printf("%d ", -1);
		}
		else {
			answer.push_back(remaining[a].back());
			remaining[a].pop_back();
		}
	}
	if(count_nopes > n - y) {
		puts("NO");
		return;
	}
	for(int i = 0; i < n; ++i) {
		if(answer[i] != nope && answer[i] != b[i] && y + count_nopes != n) {
			answer[i] = nope;
			count_nopes++;
		}
	}
	assert(y + count_nopes == n);
	puts("YES");
	for(int a : answer) {
		printf("%d ", a);
	}
	puts("");
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}

// F - (N - F) = 2 * F - N  <-  wasted