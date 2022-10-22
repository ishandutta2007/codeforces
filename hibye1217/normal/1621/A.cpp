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
		int n, k; cin >> n >> k;
		if (k > (n+1)/2){ cout << -1 << endl; continue; }
		int cnt = 0;
		for (int i = 0; i < n; i++){
			string s = "";
			for (int j = 0; j < n; j++){ s += '.'; }
			if (i % 2 == 0 && cnt < k){ s[i] = 'R'; cnt += 1; }
			cout << s << endl;
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