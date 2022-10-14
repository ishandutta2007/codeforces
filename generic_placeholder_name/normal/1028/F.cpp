// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
// Phm Trng t ORZ
 
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vll vector <ll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#pragma 03
using namespace std;
ll n, t, x, y;
unordered_map <ll, ll> sym[200000];
unordered_map <ll, set <pii> > cir;
void upd(ll v){
	n += (v >> 1);
	auto &s = cir[x * x + y * y];
	if (v == -2) s.erase({x, y});
	for (auto &[f, g] : s) sym[(x + f) / __gcd(x + f, y + g)][(y + g) / __gcd(x + f, y + g)] += v;
	sym[x / __gcd(x, y)][y / __gcd(x, y)] += (v >> 1);
	if (v == 2) s.insert({x, y});
}
int main(){
	ll q; cin >> q;
	while (q--) {
		cin >> t >> x >> y;
		if (t == 3) cout << n - sym[x / __gcd(x, y)][y / __gcd(x, y)] << '\n';
		else{
			if (t == 1) upd(2);
			else upd(-2);
		}
	}
	return 0;
}