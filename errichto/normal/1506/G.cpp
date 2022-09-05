#include <bits/stdc++.h>
using namespace std;

void test_case() {
	string s;
	cin >> s;
	int n = s.length();
	
	int start = 0;
	
	vector<int> occurrences[26];
	for(int i = n - 1; i >= 0; --i) {
		occurrences[s[i]-'a'].push_back(i);
	}
	// 'a' -> 105, 20, 7, 5
	while(true) {
		bool anything_happened = false;
		for(int use = 25; use >= 0; --use) {
			if(!occurrences[use].empty()) {
				// find first occurrence
				int where = occurrences[use].back();
				
				bool all_present = true;
				for(int c = 0; c < 26; ++c) {
					if(!occurrences[c].empty()) {
						if(occurrences[c][0] < where) {
							all_present = false;
							break;
						}
					}
				}
				if(all_present) {
					cout << s[where];
					start = where + 1;
					
					occurrences[s[where]-'a'].clear();
					for(int c = 0; c < 26; ++c) {
						while(!occurrences[c].empty() && occurrences[c].back() < start) {
							occurrences[c].pop_back();
						}
					}
					
					anything_happened = true;
					break;
				}
			}
		}
		if(!anything_happened) {
			break;
		}
	}
	cout << "\n";
	// O(26^2 * N) -> O(N + 26^2)
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}

// aezakmi

// aaiaiaZaiiaazaiaiaz
      // ^     ^     ^
      
// To know the first character:
 // try z, y, ..., a
  // find its first occurance, check if everything exists on the right