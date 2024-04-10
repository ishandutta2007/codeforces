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
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

const ll mod = 998244353;
int arr[200020], brr[200020];
int tmp[200020];

int chk[200020]; int prf[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		for (int i = 1; i <= n; i++){ cin >> brr[i]; }
		for (int i = 1; i <= n; i++){ tmp[ arr[i] ] = i; }
		for (int i = 1; i <= n; i++){ arr[i] = tmp[i]; }
		for (int i = 1; i <= n; i++){ tmp[i] = -1; }
		for (int i = 1; i <= n; i++){ if (brr[i] > 0){ tmp[ brr[i] ] = i; } }
		for (int i = 1; i <= n; i++){ brr[i] = tmp[i]; }
		for (int i = 1; i <= n; i++){ tmp[ arr[i] ] = i; }
		for (int i = 1; i <= n; i++){
			arr[i] = tmp[ arr[i] ]; if (brr[i] > 0){ brr[i] = tmp[ brr[i] ]; }
		}
		//cout << "ARR "; for (int i = 1; i <= n; i++){ cout << arr[i] << ' '; } cout << endl << flush;
		//cout << "BRR "; for (int i = 1; i <= n; i++){ cout << brr[i] << ' '; } cout << endl << flush;
		for (int i = 1; i <= n; i++){ chk[i] = 1; }
		for (int i = 1; i <= n; i++){ if (brr[i] > 0){ chk[ brr[i] ] = 0; } }
		for (int i = 1; i <= n; i++){ chk[i] += chk[i-1]; }
		for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + (brr[i] < 0); }
		ll ans = 1;
		for (int i = 1; i <= n; i++){ int j = min(i+k, n);
			if (brr[i] > 0){ int x = brr[i];
				if (x <= j){ ans *= 1; } else{ ans *= 0; }
			}
			else{
				int cnt = chk[j] - prf[i-1];
				ans *= cnt; ans %= mod;
			}
		}
		cout << ans << endl; //cout << flush;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}