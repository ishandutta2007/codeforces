#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

bool chk[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << 2 << endl;
		for (int i = 1; i <= n; i++){
			if (chk[i]){ continue; }
			int j = i; while (j <= n){ cout << j << ' '; chk[j] = 1; j *= 2; }
		}
		cout << endl;
		for (int i = 1; i <= n; i++){ chk[i] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}