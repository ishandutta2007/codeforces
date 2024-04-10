#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> trie(1, vector<int>(26, -1));
	vector<int> psh(26, -1);
	while (n--) {
		string foo;
		cin >> foo;
		int cur = 0;
		for (int i = 0; i < foo.size(); ++i) {
			if (trie[cur][foo[i] - 'a'] == -1) {
				trie[cur][foo[i] - 'a'] = trie.size();
				trie.push_back(psh);
			}
			cur = trie[cur][foo[i] - 'a']; 
		}
	}
	vector<vector<int>> dp(trie.size(), vector<int>(2));
	for (int i = trie.size() - 1; i >= 0; --i) {
		if (accumulate(trie[i].begin(), trie[i].end(), 0ll) == -26) {
	  	dp[i][1] = 1;
	  	continue;
		}
		for (int j = 0; j < 26; ++j) {
			if (trie[i][j] != -1) {
				int ch = trie[i][j];
				dp[i][0] |= !(dp[ch][0]);
				dp[i][1] |= !(dp[ch][1]);
			}
		}
	}
	/*
	for (int i = 0; i < trie.size(); ++i) {
		cout << i << " are ";
		for (int j = 0; j < 26; ++j) if (trie[i][j] != -1) cout << (char)('a' + j) << ' ';
		cout << '\n';
	}
	*/
	cerr << dp[0][1] << ' ' << dp[0][0] << '\n';
	if (dp[0][1] && dp[0][0]) {
		cout << "First";
	} else if (!dp[0][0]) {
		cout << "Second";		
	} else cout << (k&1 ? "First" : "Second");  
	cout << '\n';
}