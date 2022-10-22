#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



void Main(){
	int t; cin >> t;
	while (t--){
		string str; cin >> str; string s = "..........";
		int ans = 10;
		for (int x = 0; x < 1024; x++){
			int res = 10;
			int a = 0, b = 0, al = 5, bl = 5;
			for (int b = 0; b < 10; b++){
				int bit = 1<<b;
				s[b] = (x&bit) ? '1' : '0';
				if (str[b] != '?' && s[b] != str[b]){ goto done; }
			}
			for (int i = 0; i < 10; i++){
				int& x = (i&1) ? b : a; int& y = (i&1) ? a : b;
				int& xl = (i&1) ? bl : al; int& yl = (i&1) ? al : bl;
				if (x+xl < y || y+yl < x){ res = i; goto done; }
				if (s[i] == '1'){ x += 1; } xl -= 1;
			}
			done: ans = min(ans, res);
		}
		cout << ans << endl;
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