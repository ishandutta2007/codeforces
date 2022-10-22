#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	bitset<26> start;
	pair<int,int> letter[26];
	memset(letter, -1, sizeof(letter));
	int count[26];

	set<char> seen;
	string ans = "";

	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		start[s[0]-'a'] = true;
		memset(count, 0, sizeof(count));
		for (int j = 0; j < s.size(); j++) {
			seen.insert(s[j]);
			if (count[s[j]-'a'] > 0)
				goto bad;
			count[s[j]-'a']++;
			if (j > 0) {
				if (letter[s[j]-'a'].first != -1 && letter[s[j]-'a'].first != s[j-1]-'a')
					goto bad;
				if (letter[s[j-1]-'a'].second != -1 && letter[s[j-1]-'a'].second != s[j]-'a') 
					goto bad;
				letter[s[j]-'a'].first = s[j-1]-'a';
				letter[s[j-1]-'a'].second = s[j]-'a';
			}
			if (j+1 < s.size()) {
				if (letter[s[j]-'a'].second != -1 && letter[s[j]-'a'].second != s[j+1]-'a')
					goto bad;
				if (letter[s[j+1]-'a'].first != -1 && letter[s[j+1]-'a'].first != s[j]-'a')
					goto bad;
				letter[s[j]-'a'].second = s[j+1]-'a';
				letter[s[j+1]-'a'].first = s[j]-'a';
			}
		}
	}
	
	for (int i = 0; i < 26; i++) {
		if (start[i] && letter[i].first == -1) {
			for (int cur = i; cur != -1; cur = letter[cur].second) {
				ans.push_back(cur+'a');
				seen.erase(cur+'a');
			}
		}
	}
	if (seen.empty()) 
		cout << ans << nl;
	else
		goto bad;

	return 0;

	bad:
	cout << "NO" << nl;
	
	return 0;
}