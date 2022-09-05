#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<vector<int>> steps;
bool ok = true;
bitset<40> memo_prefix[41];
 
void rec(int i_step, bitset<40> is_one, bitset<40> is_question) {
	if(i_step == (int) steps.size()) {
		// check if a sorted
		if(is_question != 0) {
			ok = false;
			return;
		}
		// for(int i = 0; i < n; ++i) {
			// if(is_question[i]) {
				// ok = false;
				// return;
			// }
		// }
		int prefix = is_one.count();
		if(is_one != memo_prefix[prefix]) {
			ok = false;
			return;
		}
		// for(int i = 0; i < n - 1; ++i) {
			// if(is_one[i] && !is_one[i+1]) {
				// ok = false;
				// return;
			// }
		// }
		return;
	}
	vector<int> step = steps[i_step];
	int ones = 0, zeros = 0, question = 0;
	for(int i : step) {
		if(is_question[i]) { // popcount!
			question++;
		}
		else if(!is_one[i]) {
			zeros++;
		}
		else {
			ones++;
		}
		is_question[i] = false;
		is_one[i] = true;
	}
	for(int i = 0; i < zeros; ++i) {
		is_one[step[i]] = 0;
	}
	rec(i_step + 1, is_one, is_question);
	for(int i = zeros; i < zeros + question; ++i) {
		is_one[step[i]] = 0;
		// if(i_step + 1 == (int) steps.size() && i != zeros - question - 1) {
			// continue;
		// }
		rec(i_step + 1, is_one, is_question);
	}
}
 
int main() {
	int k;
	cin >> n >> k;
	
	for(int p = 0; p <= n; ++p) {
		memo_prefix[p] = 0;
		for(int i = 0; i < p; ++i) {
			memo_prefix[p][n-1-i] = 1;
		}
	}
	
	steps.resize(k);
	for(vector<int>& step : steps) {
		int cnt;
		scanf("%d", &cnt);
		while(cnt--) {
			int i;
			scanf("%d", &i);
			step.push_back(i - 1);
		}
	}
	bitset<40> is_one = 0;
	bitset<40> is_question = 0;
	for(int i = 0; i < n; ++i) {
		is_question[i] = true;
	}
	rec(0, is_one, is_question);
	puts(n == 1 || ok ? "ACCEPTED" : "REJECTED");
}