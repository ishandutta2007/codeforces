#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	bitset<26> letter;
	string s; 
	int k;
	cin >> s;
	cin >> k;
	for (int i = 0; i < s.size(); i++)
		letter[s[i]-'a'] = true;
	int sum = 0;
	for (int i = 0; i < 26; i++)
		sum += letter[i];
	if (k > s.size()) cout << "impossible" << endl;
	else cout << max(0, k-sum) << endl;

	return 0;
}