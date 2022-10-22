#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// #define DEBUG

int n; bool res[10020];
bool ans[10020];

inline bool ask(int a, int b, int c){
	if (a > n){ a -= n; } if (b > n){ b -= n; } if (c > n){ c -= n; }
	cout << "? " << a << ' ' << b << ' ' << c << endl << flush;
	int res; cin >> res;
	return res;
}

void Main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){ res[i] = ask(i, i+1, i+2); }
		int a = -1, b = -1;
		for (int i = 1; i <= n; i++){
			int i1 = i, i2 = i+1; if (i2 > n){ i2 -= n; }
			if (res[i1] && !res[i2]){ a = i1; b = i1+3; }
		}
		if (b > n){ b -= n; }
		for (int i = 1; i <= n; i++){
			if (i == a){ ans[i] = 1; }
			else if (i == b){ ans[i] = 0; }
			else{ ans[i] = ask(a, b, i); }
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){ if (!ans[i]){ cnt += 1; } }
		cout << "! " << cnt;
		for (int i = 1; i <= n; i++){
			if (!ans[i]){ cout << ' ' << i; }
		}
		cout << endl << flush;
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