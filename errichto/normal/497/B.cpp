#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> in(n);
	for(int i = 0; i < n; ++i) {
		cin >> in[i];
	}
	vector<pair<int,int>> gather;
	
	vector<vector<int>> where(2, vector<int>(2*n+1, INT_MAX)); // int[2][n+1]
	vector<vector<int>> prefix_sum(2, vector<int>(n));
	for(int i = 0; i < n; ++i) {
		int x = in[i] - 1; // 0 or 1
		if(i != 0) {
			prefix_sum[0][i] = prefix_sum[0][i-1];
			prefix_sum[1][i] = prefix_sum[1][i-1];
		}
		++prefix_sum[x][i];
		int count = prefix_sum[x][i];
		where[x][count] = i;
	}
	for(int i = 0; i < n; ++i) {
		assert(prefix_sum[0][i] + prefix_sum[1][i] == i + 1);
	}
	// 1 2 2 1 1 1 1 ... | 8x 2 or 10x 1
	// 5x 2, 7x 1, t = 3
	for(int t = 1; t <= n; ++t) {
		int next_index = 0;
		int sets_A = 0, sets_B = 0;
		bool is_ok = true;
		int s = -1;
		while(next_index < n) {
			vector<int> count(2); // int count[2];
			if(next_index != 0) {
				for(int i = 0; i < 2; ++i) {
					count[i] = prefix_sum[i][next_index-1];
				}
			}
			// 0 -> count[0] + t, or   1 -> count[1] + t
			int jump_A = where[0][count[0]+t];
			int jump_B = where[1][count[1]+t];
			int jump_to = min(jump_A, jump_B);
			if(jump_to < n) {
				assert(jump_A != jump_B);
				next_index = jump_to + 1;
				if(jump_to == jump_A) {
					++sets_A;
					assert(in[jump_A] == 1);
					if(next_index == n && sets_A > sets_B) {
						s = sets_A;
					}
				}
				else {
					++sets_B;
					if(next_index == n && sets_B > sets_A) {
						s = sets_B;
					}
				}
			}
			else {
				//~ is_ok = false;
				break;
			}
		}
		if(next_index < n) {
			is_ok = false;
		}
		if(s == -1) {
			is_ok = false;
		}
		if(is_ok) {
			gather.push_back({s, t});
		}
	}
	sort(gather.begin(), gather.end());
	cout << gather.size() << "\n";
	for(pair<int,int> p : gather) {
		cout << p.first << " " << p.second << "\n";
	}
}