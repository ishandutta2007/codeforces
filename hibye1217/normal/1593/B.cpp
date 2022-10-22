#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int f(ll x, int tar){
	int cnt = 0;
	while (x >= 10 && x%100 != tar){
		if (x%10 == tar%10){ x = (x/100)*10 + x%10; }
		else{ x = x/10; }
		cnt += 1;
	}
	if (x < 10){ return 1e9; }
	else{ return cnt; }
}

void Main(){
	int t; cin >> t;
	while (t--){
		ll x; cin >> x;
		cout << min({ f(x, 0), f(x, 25), f(x, 50), f(x, 75) }) << endl;
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