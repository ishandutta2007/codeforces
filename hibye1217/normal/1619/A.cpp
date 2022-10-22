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

// #define DEBUG



void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int sl = s.size();
		if (sl % 2 != 0){ cout << "NO" << endl; continue; }
		bool flg = 1;
		for (int i = 0; i < sl/2; i++){
			int i1 = i, i2 = i + sl/2;
			if (s[i1] != s[i2]){ flg = 0; }
		}
		if (flg){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
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