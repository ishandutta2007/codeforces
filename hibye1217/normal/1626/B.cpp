#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bnt(x) __builtin_popcount(x)



// #define DEBUG



void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s; int sl = s.size();
		int idx = -1;
		for (int i = 1; i < sl; i++){
			if ((int)s[i-1]+s[i]-'0'-'0' >= 10){ idx = i; }
		}
		if (idx == -1){
			cout << (int)s[0]+s[1]-'0'-'0';
			for (int i = 2; i < sl; i++){ cout << s[i]; }
		}
		else{
			for (int i = 0; i < sl; i++){
				if (i == idx-1){ cout << (int)s[idx-1]+s[idx]-'0'-'0'; }
				else if (i == idx){  }
				else{ cout << s[i]; }
			}
		}
		cout << endl;
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