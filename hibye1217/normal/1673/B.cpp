#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

int prf[30][200020], ptr[30];

void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s; int sl = s.size(); s = " " + s;
		vector<int> chs;
		for (int i = 1; i <= sl; i++){ chs.push_back(s[i]-96); }
		unq(chs);
		for (int i = 1; i <= sl; i++){
			for (int j = 1; j <= 26; j++){ prf[j][i] = prf[j][i-1]; }
			prf[ s[i]-96 ][i] += 1;
		}
		for (int i = 1; i <= 26; i++){ ptr[i] = 0; }
		for (int i = 1; i <= sl; i++){
			int ch = s[i]-96;
			if (ptr[ch] != 0){
				int st = ptr[ch], ed = i;
				for (int c : chs){
					if (c == ch){ continue; }
					if (prf[c][ed] - prf[c][st] == 0){ cout << "No"; goto next; }
				}
			}
			ptr[ch] = i;
		}
		cout << "Yes";
		next: cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}