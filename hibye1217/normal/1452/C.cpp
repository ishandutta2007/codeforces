#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

void solve(){
	string s;
	cin >> s;
	int ans = 0;
	int bracket1 = 0, bracket2 = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){ bracket1 += 1; }
		if (s[i] == '['){ bracket2 += 1; }
		if (s[i] == ')'){
			bracket1 -= 1;
			if (bracket1 >= 0){ ans += 1; }
			else{ bracket1 = 0; }
		}
		if (s[i] == ']'){
			bracket2 -= 1;
			if (bracket2 >= 0){ ans += 1; }
			else{ bracket2 = 0; }
		}
	}
	cout << ans << endl;
}

int main(){
	FastIO;
	int t;
	cin >> t;
	while (t--){ solve(); }
}