#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		int n;
		cin >> n >> s;              
		string tar = "abacaba";
		bool ok = false;
		for (int i = 0; i < n - 6; ++i) {   
			string New = s;
			bool ok2 = true;
			for (int pos = 0; pos < 7; ++pos) {
				int cur = i + pos;
				if (s[cur] != tar[pos] && s[cur] != '?')	ok2 = false;
				New[cur] = tar[pos];	
			}	
			if (!ok2) continue;
			int ct = 0;
			for (int j = 0; j < n - 6; ++j) {
				bool ok3 = true;
				for (int pos = 0; pos < 7; ++pos) {
					if (New[j + pos] != tar[pos] || New[j + pos] == '?') ok3 = false;					
				}				
				ct += ok3;
			}
			if (ct == 1) {
				cout << "Yes\n";
				for (char c : New) cout << (c == '?' ? 'z' : c);
				ok = true;
				break;
			}
		} 
		if (!ok) cout << "No";
		cout << '\n';
	}
}