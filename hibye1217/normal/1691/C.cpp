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



void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int cnt = 0; int i1 = -1, i2 = -1;
		for (int i = 0; i < n; i++){
			if (s[i] == '1'){
				cnt += 1;
				if (i1 == -1){ i1 = i; } i2 = i;
			}
		}
		if (cnt == 0){ cout << 0 << endl; }
		else if (cnt == 1){
			int k1 = i1, k2 = (n-1) - i2;
			if (k >= k2){ cout << 1 << endl; }
			else if (k >= k1){ cout << 10 << endl; }
			else{ cout << 11 << endl; }
		}
		else{
			int k1 = i1, k2 = (n-1) - i2;
			if (k >= k2+k1){ cout << (cnt-2)*11 + 10 + 1 << endl; }
			else if (k >= k2){ cout << (cnt-1)*11 + 1 << endl; }
			else if (k >= k1){ cout << (cnt-1)*11 + 10 << endl; }
			else{ cout << cnt*11 << endl; }
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}