#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

// #define DEBUG

bool f(string s1, string s2){
	//cout << "F " << s1 << ' ' << s2 << endl;
	if (s1 == s2){ return 1; }
	int l1 = s1.size(), l2 = s2.size();
	for (int j = 0; j < l2; j++){
		bool chk = 1;
		int st1 = 0, st2 = j;
		int ed1 = st1+l1-1, ed2 = st2+l1-1;
		if (ed2 >= l2){ break; }
		for (int i = 0; i < st2; i++){ if (s2[i] == '0'){ chk = 0; } }
		//cout << "I1 " << j << ' ' << chk << endl;
		for (int i = 0; i < l1; i++){
			if (s1[i+st1] != s2[i+st2]){ chk = 0; }
		}
		//cout << "I2 " << j << ' ' << chk << endl;
		for (int i = ed2+1; i < l2; i++){ if (s2[i] == '0'){ chk = 0; } }
		//cout << "I3 " << j << ' ' << chk << endl;
		if (s1[l1-1] == '0' && ed2 == l2-1){ chk = 0; }
		if (chk){ return 1; }
	}
	return 0;
}

void Main(){
	ll x, y; cin >> x >> y;
	string sx = "", sy = "";
	bool fx = 0, fy = 0;
	for (int i = 60; i >= 0; i--){
		if (x & 1LL<<i){ fx = 1; }
		if (y & 1LL<<i){ fy = 1; }
		if (fx){ if (x & 1LL<<i){ sx += '1'; } else{ sx += '0'; } }
		if (fy){ if (y & 1LL<<i){ sy += '1'; } else{ sy += '0'; } }
	}
	int lx = sx.size(), ly = sy.size();
	string rx1 = "", rx2 = "1"; bool f3 = 0;
	for (int i = lx-1; i >= 0; i--){
		if (sx[i] == '1'){ f3 = 1; }
		if (f3){ rx1 += sx[i]; } rx2 += sx[i];
	}
	string sxx = ""; int lrx = rx1.size();
	for (int i = lrx-1; i >= 0; i--){ sxx += rx1[i]; }
	if ( f(sx, sy) || f(rx1, sy) || f(rx2, sy) || f(sxx, sy) ){ cout << "YES"; }
	else{ cout << "NO"; }
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