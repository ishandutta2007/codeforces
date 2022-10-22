#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ld = long double;

void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int sl = s.size();
		bool ans = sl != 1;
		for (int i = 1; i < sl-1; i++){
			ans &= (s[i-1]==s[i] || s[i]==s[i+1]);
		}
		if (ans){ ans &= (s[0] == s[1]); ans &= (s[sl-2] == s[sl-1]); }
		if (ans){ cout << "Yes" << endl; } else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}