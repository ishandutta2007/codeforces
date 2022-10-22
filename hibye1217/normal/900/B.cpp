#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool chk[100020];

void Main(){
	int a, b, c; cin >> a >> b >> c;
	for (int ans = 1; !chk[a]; ans++){
		chk[a] = 1; if (a*10 / b == c){ cout << ans; return; }
		a = a*10 % b;
	}
	cout << -1;
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