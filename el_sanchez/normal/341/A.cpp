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
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 1111;
                    
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n;
vector<ll> a;
ll s1, s2, s, p, q;

int main() {

	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	sort(all(a));

	s1 = 0;
	forn(i, n)
		s1 += a[i];

	s = s1;
	s2 = 0;
	for (int i = 0; i < n; i++) {
		s -= a[i];
		s2 += (s - 1ll * a[i] * (n - 1 - i));
	}
	s2 *= 2;
	
	p = s1 + s2;
	q = n;
	s = gcd(p, q);
	p /= s;
	q /= s;
	cout << p << ' ' << q << '\n';
	
	return 0;
}