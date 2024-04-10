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

int arr[2020][2020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int one = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				char ch; cin >> ch; arr[i][j] = ch-'0';
				if (ch == '1'){ one += 1; }
			}
		}
		int ans = n*n;
		for (int i = 0; i < n; i++){
			int res = 0, ro = one;
			for (int j = 0; j < n; j++){
				if (arr[j][(i+j)%n] == 1){ ro -= 1; }
				else{ res += 1; }
			}
			ans = min(ans, res+ro);
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}