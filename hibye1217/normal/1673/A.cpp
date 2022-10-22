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



void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s; int sl = s.size();
		int sum = 0;
		for (char ch : s){ sum += ch-96; }
		if (sl & 1){
			int val = min(s[0], s[sl-1]) - 96;
			if (sl == 1){ cout << "Bob "; } else{ cout << "Alice "; }
			cout << abs(sum - 2*val) << endl;
		}
		else{
			cout << "Alice " << sum << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}