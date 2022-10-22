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
typedef pair<ll, pl2> pl3;



void Main(){
	int n; cin >> n;
	int a = -1, b = 0;
	for (int i = 1; i <= n; i++){
		b += 1;
		if (a+3 == b){ a += 2; b -= 1; }
	}
	a = (a+1) / 2;
	//cout << a << ' ' << b << endl;
	vector<pi2> ans;
	for (int i = 1; i <= a; i++){ ans.push_back({a+1 + a-i, a+1 + i-1}); }
	for (int i = 1; i < a; i++){ ans.push_back({a+a+1 + a-1-i, a+a+1 + i-1}); }
	for (int i = max(a+a+a, 1); i <= n; i++){ ans.push_back({i, i}); }
	cout << ans.size() << endl;
	for (pi2 p : ans){ cout << p.fr << ' ' << p.sc << endl; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}