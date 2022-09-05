#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> red; // positions of red columns
	int max_so_far = -1;
	int best_non_red = INT_MAX;
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		if(p[i] > max_so_far) {
			red.push_back(i);
			max_so_far = p[i];
		}
		else {
			best_non_red = min(best_non_red, p[i]);
		}
	}
	// #warning TODO: what if we dont remove red?
	// 1 3 5 2 7
	
	int init_reds = red.size();
	cerr << "init_reds = " << init_reds << endl;
	red.push_back(n);
	cerr << "red: ";
	// for(int x : red) { 
		// cerr << x << " ";
	// }
	// cerr << endl;
	int answer = -1;
	int whom_remove = -1;
	if(best_non_red != INT_MAX) {
		whom_remove = best_non_red;
		answer = init_reds;
	}
	for(int i_red = 0; i_red < (int) red.size() - 1; ++i_red) {
		int i = red[i_red];
		int j = red[i_red+1];
		// consider removing column i
		max_so_far = (i_red == 0 ? -1 : p[red[i_red-1]]);
		int new_reds = 0;
		for(int k = i + 1; k < j; ++k) {
			if(p[k] > max_so_far) {
				new_reds++;
				max_so_far = p[k];
			}
		}
		int candidate = init_reds - 1 + new_reds;
		// cerr << i << ", " << j << ", " << new_reds << endl;
		if(candidate > answer) {
			answer = candidate;
			whom_remove = p[i];
		}
		else if(candidate == answer && p[i] < whom_remove) {
			answer = candidate;
			whom_remove = p[i];
		}
	}
	cout << whom_remove << "\n";
	cerr << "answer = " << answer << "\n";
}