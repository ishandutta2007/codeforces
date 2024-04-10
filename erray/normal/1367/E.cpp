#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string str;
		cin >> n >> k >> str;
		vector<int> ct(26);
		for (char c : str) ct[c - 'a']++;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int nec = i / __gcd(i, k);
			long long co = 0;
			for (int i = 0; i < 26; ++i) co += ct[i] - ct[i] % nec;
			if (co >= i) ans = i; 		
		}
		cout << ans << '\n';
	}
}