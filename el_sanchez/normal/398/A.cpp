#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

ll a, b, p, q, d, pp, qq;
ll ans, cur;
string s;
vector<string> w[2];

int main() {

	cin >> a >> b;
	
	if (a == 0) {
		cout << -1ll * b * b << '\n';
		forn(i, b)
			cout << 'x';
		return 0;
	}
	if (b == 0) {
		cout << 1ll * a * a << '\n';
		forn(i, a)
			cout << 'o';
		return 0;
	}
	
	ans = -1E18;
	for (ll p = 1; p <= a; p++) {
		for (ll q = max(1ll, p - 1); q <= min(b, p + 1); q++) {
			cur = sqr(a - p + 1) + p - 1;
            ll k1 = b % q, k2 = q - k1;
            ll d1 = b / q + 1, d2 = b / q;
            cur -= k1 * d1 * d1 + k2 * d2 * d2;

            if (cur > ans) {
            	ans = cur;
            	pp = p;
            	qq = q;
            }		
        }		
	}
	
	cout << ans << endl;
	
	s = "";
	forn(i, a - pp + 1)
		s += 'o';
	w[0].pb(s);
	forn(i, pp - 1) {
		s = "o";
		w[0].pb(s);  
	}
	
	forn(i, b % qq) {
		s = "";
		forn(j, b / qq + 1)
			s += 'x';
		w[1].pb(s);	
	}
	
	forn(i, qq - b % qq) {
		s = "";
		forn(j, b / qq)
			s += 'x';
		w[1].pb(s);	
	}
	
	if (w[0].size() < w[1].size())
		swap(w[0], w[1]);
	if (w[0].size() > w[1].size())
		w[1].pb("");

	forn(i, w[0].size())
		cout << w[0][i] << w[1][i];
		
	return 0;
}