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

int arr[200020];
int fen[262150], N;
void upd(int pos, int val){
	for (int i = pos; i < N; i += i&-i){ fen[i] += val; }
}
int qry(int pos){
	int res = 0;
	for (int i = pos; i > 0; i -= i&-i){ res += fen[i]; }
	return res;
}
// Submit Ignored :blobcry:
int ans[200020];
void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; ll cnt = 0;
		N = 1; while (N <= n){ N <<= 1; }
		for (int i = 1; i < N; i++){ fen[i] = 0; }
		for (int i = 1; i <= n; i++){ cin >> arr[i]; cnt += arr[i]; }
		for (int i = 1; i <= n; i++){ upd(i, arr[i] - arr[i-1]); }
		cnt /= n;
		for (int i = n; i >= 1; i--){
			upd(i-cnt+1, -1); upd(i+1, 1);
			int res = qry(i);
			if (res != 0){ ans[i] = 1; cnt -= 1; } else{ ans[i] = 0; }
			//for (int j = 1; j <= n; j++){ cout << qry(j) << ' '; }
			//cout << endl;
		}
		if (cnt > 0){ ans[1] = 1; }
		for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}