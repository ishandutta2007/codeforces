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

const int N = 131072;
int arr[100020];
int fen[131080];

void upd(int pos, int val){
	for (int i = pos; i < N; i += i&-i){ fen[i] += val; }
}
int qry(int pos){
	int res = 0;
	for (int i = pos; i > 0; i -= i&-i){ res += fen[i]; }
	return res;
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int ans = 0;
		for (int i = 1; i <= n; i++){
			upd(arr[i], 1);
			if (qry(i) == i){ ans += 1; }
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){ upd(i, -1); }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}