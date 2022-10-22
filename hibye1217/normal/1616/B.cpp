#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

string rev(string x){ int xl = x.size();
	string y = "";
	for (int i = xl-1; i >= 0; i--){ y += x[i]; }
	return y;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int sl; cin >> sl;
		string s; cin >> s;
		if (sl == 1){ cout << s << s << endl; continue; }
		string ans = s.substr(0, 1); ans += ans;
		ans = min(ans, s + rev(s));
		int idx = -1;
		for (int i = 1; i < sl; i++){
			if (s[i-1] < s[i]){ idx = i; break; }
		}
		if (idx == -1){ cout << ans << endl; continue; }
		else{
			string st = s.substr(0, idx); st += rev(st);
			cout << min(ans, st) << endl;
		}
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}