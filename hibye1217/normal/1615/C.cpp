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



void Main(){
	int t; cin >> t;
	while (t--){
		int sl; cin >> sl;
		string s1, s2; cin >> s1 >> s2;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < sl; i++){
			if (s1[i] == '1'){ c1 += 1; }
			if (s2[i] == '1'){ c2 += 1; }
		}
		int ans = 1e9;
		if (c1 == c2){
			int res = 0;
			for (int i = 0; i < sl; i++){
				if (s1[i] != s2[i]){ res += 1; }
			}
			res /= 2;
			ans = min(ans, 2*res);
		}
		if (sl - (c1-1) == c2){
			string s3 = "";
			bool chk = 0;
			for (int i = 0; i < sl; i++){
				if (s1[i] == s2[i] && chk == 0){
					chk = 1;
					s3 += s1[i];
				}
				else{
					if (s1[i] == '1'){ s3 += '0'; }
					if (s1[i] == '0'){ s3 += '1'; }
				}
			}
			if (chk == 0){
				for (int i = 0; i < sl; i++){
					if (s1[i] == '1'){ s3[i] = '1'; break; }
				}
			}
			int res = 0;
			for (int i = 0; i < sl; i++){
				if (s3[i] != s2[i]){ res += 1; }
			}
			res /= 2;
			ans = min(ans, 2*res+1);
		}
		if (ans == 1e9){ cout << -1 << endl; }
		else{ cout << ans << endl; }
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