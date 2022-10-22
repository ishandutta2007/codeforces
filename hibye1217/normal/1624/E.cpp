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

typedef pair<int, pi2> pi3;

// #define DEBUG

map<string, pi3> mp;
pi3 dp[1020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, sl; cin >> n >> sl;
		for (int i = 0; i <= sl; i++){ dp[i] = { -1, {-1, -1} }; }
		for (int i = 1; i <= n; i++){
			string s; cin >> s;
			for (int st = 0; st < sl; st++){
				for (int ed : {st+1, st+2}){
					if (ed >= sl){ continue; }
					string str = s.substr(st, 2);
					if (ed == st+2){ str += s[st+2]; }
					mp[str] = { i, {st+1, ed+1} };
				}
			}
		}
		string s; cin >> s;
		dp[0] = { 0, {0, 0} };
		for (int i = 1; i <= sl; i++){
			for (int j : {i-2, i-3}){
				if (j < 0){ continue; }
				if (dp[j].fr == -1){ continue; }
				string str = s.substr(j, 2);
				if (j == i-3){ str += s[j+2]; }
				if ( mp.count(str) ){
					//cout << str << endl;
					dp[i] = mp[str];
				}
			}
			//cout << "dp " << i << ' ' << dp[i].fr << ' ' << dp[i].sc.fr << ' ' << dp[i].sc.sc << endl;
		}
		if (dp[sl].fr == -1){ cout << -1 << endl; }
		else{
			int ptr = sl;
			stack<pi3> stk;
			while (ptr > 0){
				stk.push(dp[ptr]);
				ptr -= (dp[ptr].sc.sc - dp[ptr].sc.fr + 1);
			}
			cout << stk.size() << endl;
			while (!stk.empty()){
				pi3 p = stk.top(); stk.pop();
				cout << p.sc.fr << ' ' << p.sc.sc << ' ' << p.fr << endl;
			}
		}
		mp.clear();
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