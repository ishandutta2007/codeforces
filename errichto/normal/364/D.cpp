#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

ll t[nax];
int n;
set<ll> s;
vector<ll> w;
vector<ll> kol;

bool Ok(ll x) {
	if(n < 10000) {
		int licz = 0;
		RE(i, n) if(t[i] % x == 0LL) licz++;
		return licz * 2 >= n;
	}
	int k = 300;
	int licz = 0;
	RE(i, k) if(t[i] % x == 0LL) licz++;
	if(licz < 90) return false;
	licz = 0;
	RE(i, n) if(t[i] % x == 0LL) licz++;
	return licz * 2 >= n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	srand(57);
	cin >> n;
	RE(i, n) cin >> t[i];
	random_shuffle(t, t + n);
	int k = 10;
	if(n < 40) k = n;
	if(n > 200000) k = 10;
	for(int i = 0; i < k && s.size() < 30123; ++i) {
		ll a = t[i];
		for(ll i = 1LL; i * i <= a; ++i) {
			if(a % i == 0LL) {
				s.insert(i);
				s.insert(a / i);
			}
		}
	}
	for(auto x : s) w.pb(x);
	ll res = 1;
	while(!w.empty()) {
		int i = (int)w.size() / 10;
		if(Ok(w[i])) {
			kol.clear();
			maxi(res, w[i]);
			for(auto x : w) if(x > w[i]) kol.pb(x);
			w = kol;
		}
		else {
			kol.clear();
			for(auto x : w) if(x % w[i] != 0LL) kol.pb(x);
			w = kol;
		}
	}
	cout << res;
	return 0;
}