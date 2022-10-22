#include <bits/stdc++.h>
using namespace std;

string s, ans;
int n;

int main(){
	cin >> s;
	n = s.length();
	for (int mask = 1; mask < (1 << n); mask++){
		string t;
		for (int i = 0; i < n; i++){
			if (mask >> i & 1) t.push_back(s[i]); 
		}
		string rev = t;
		reverse(rev.begin(), rev.end());
		if (rev != t) continue;
		if (t > ans) ans = t;
	}
	cout << ans << endl;
	return 0;
}