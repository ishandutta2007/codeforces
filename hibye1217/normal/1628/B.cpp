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



void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		set<string> s; bool flg = 0;
		for (int i = 1; i <= n; i++){
			string str; cin >> str;
			int sl = str.size();
			if (sl == 1){ flg = 1; }
			if (sl == 2){
				string rev = "";
				for (int i = 1; i >= 0; i--){ rev += str[i]; }
				if (s.count(rev)){ flg = 1; }
				for (char c = 'a'; c <= 'z'; c++){
					if (s.count(rev+c)){ flg = 1; }
				}
				if (str[0] == str[1]){ flg = 1; }
			}
			if (sl == 3){
				string rev = "";
				string r2 = "";
				for (int i = 2; i >= 0; i--){ rev += str[i]; }
				for (int i = 2; i >= 1; i--){ r2 += str[i]; }
				if (s.count(rev)){ flg = 1; }
				if (s.count(r2)){ flg = 1; }
				if (str[0] == str[2]){ flg = 1; }
			}
			s.insert(str);
		}
		if (flg){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}