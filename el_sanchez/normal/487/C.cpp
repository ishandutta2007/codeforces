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

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
              
int n;

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = int (res * 1ll * a % p),  --b;
		else
			a = int (a * 1ll * a % p),  b >>= 1;
	return res;
}
 
int generator (int p) {
	for (int i = 2; i < p; i++)
		if (p % i == 0)
			return -1;
			
	vector<int> fact;
	int phi = p-1,  n = phi;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
                        		
	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	
	return -1;
}

ll dzeta[111111];

int main() {

	cin >> n;	
	if (n == 1) {
		cout << "YES\n";
		cout << 1;		
	}
	if (n == 2) {
		cout << "YES\n";
		cout << 1 << '\n';
		cout << 2 << '\n';		
	}
	if (n == 3) {
		cout << "YES\n";
		cout << 1 << '\n';
		cout << 2 << '\n';		
		cout << 3 << '\n';		
	}
	if (n == 4) {
		cout << "YES\n";
		cout << 1 << '\n';
		cout << 3 << '\n';		
		cout << 2 << '\n';
		cout << 4 << '\n';		
	}
	if (n <= 4)
		return 0;
		
	dzeta[0] = 1;
	dzeta[1] = generator(n);
	for (int i = 2; i <= n - 2; i++)
		dzeta[i] = (dzeta[i - 1] * dzeta[1]) % n;
		
	if (dzeta[1] == -1)
		cout << "NO";
	else {
		cout << "YES\n";
		int pos = 0;
		cout << dzeta[pos] << '\n';
		for (int i = 1, j = n - 3; i < n - 2; i += 2, j -= 2) {
			cout << dzeta[i] << '\n';
			cout << dzeta[j] << '\n';		
		}
		cout << dzeta[n - 2] << '\n';
		cout << n << '\n';	
	}
	
	return 0;
}