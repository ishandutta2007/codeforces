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
typedef pair<pi2, pi2> pi4;

string mp[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		vector<pi4> ans;
		if (mp[0][0] == '1'){ cout << -1 << endl; goto done; }
		for (int i = 0; i < n; i++){
			for (int j = m-1; j > 0; j--){
				if (mp[i][j] == '1'){ ans.push_back({ {i, j-1}, {i, j} }); }
			}
		}
		for (int i = n-1; i > 0; i--){
			if (mp[i][0] == '1'){ ans.push_back({ {i-1, 0}, {i, 0} }); }
		}
		cout << ans.size() << endl;
		for (pi4 p : ans){
			cout << p.fr.fr+1 << ' ' << p.fr.sc+1 << ' ' << p.sc.fr+1 << ' ' << p.sc.sc+1 << endl;
		}
		done: ;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}