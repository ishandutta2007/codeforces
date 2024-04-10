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

const int N = 30;
//ll x = 1<<28;

ll ask(ll a, ll b){
	cout << "? " << a << ' ' << b << endl << flush;
	ll x; cin >> x; return x;
	//return __gcd(x+a, x+b);
}

void Main(){
	int t; cin >> t;
	//int t = 1;
	while (t--){
		ll dif = 0;
		for (int i = 0; i < N; i++){
			ll bit = 1LL << (i+1);
			ll res = 0;
			if (dif+bit+bit <= 2'000'000'000){ res = ask(dif+bit, dif+bit+bit); }
			else if (dif != 0){ res = ask(dif+bit, dif); }
			if (res != bit){ dif += bit>>1; }
		}
		cout << "! " << (1LL<<N) - dif << endl << flush;
		//cout << "ANSWER " << x << endl << flush;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}