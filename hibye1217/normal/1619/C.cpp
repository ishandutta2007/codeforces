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
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )

// #define DEBUG



void Main(){
	int t; cin >> t;
	while (t--){
		string a, s; cin >> a >> s;
		int al = a.size(), sl = s.size();
		string b = "";
		int pa = al-1, ps = sl-1;
		bool chk = 0;
		if (a == s){ cout << -1; goto nxt; }
		while (0 <= pa){
			if (ps < 0){ cout << -1; goto nxt; }
			int c = (s[ps] - a[pa] + 10) % 10;
			bool flg = (c + a[pa]-'0' >= 10);
			b = (char)(c+'0') + b;
			ps -= 1; pa -= 1;
			if (flg){
				if (ps < 0){ cout << -1; goto nxt; }
				if (s[ps] != '1'){ cout << -1; goto nxt; }
				ps -= 1;
			}
		}
		while (ps >= 0){ b = s[ps] + b; ps -= 1; }
		for (char ch : b){
			if (ch != '0'){ chk = 1; }
			if (chk){ cout << ch; }
		}
		nxt: cout << endl;
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