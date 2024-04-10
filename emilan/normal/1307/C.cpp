#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
    string s;
    cin >> s;

	map<pair<char, char>, long long> cnt;
    vector<int> freq(26);
	for (int i = 0; i < (int)s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (!freq[j]) continue;
			cnt[{j + 'a', s[i]}] += freq[j];
		}
		freq[s[i] - 'a']++;
	}
	
	sort(freq.rbegin(), freq.rend());
	long long mx = freq[0];
	for (auto i : cnt) mx = max(mx, i.second);
	
	cout << mx;

    return 0;
}