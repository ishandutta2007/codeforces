#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.00000001;
const int INF = 1E9;
const int MAXN = 100000;

vector<vector<int> > a;
vector<int> k;
int n, c;

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	k.push_back(0); k.push_back(0);
	k[0] = 1, k[1] = 2;
	a.push_back(k);
	k[0] = 2, k[1] = 3;
	a.push_back(k);
	k[0] = 1, k[1] = 3;
	a.push_back(k);

	cin >> n;
	n -= 3;
	c = 4;
	while (n >= a.size()) {
		n -= a.size();
		k.clear();
		a.push_back(k);
		forn(i, a.size()-1) {
			a[i].push_back(c);
			a.back().push_back(c);	
			c++;
		}
	}

	cout << a.size() << endl;
	forn(i, a.size()) {
		forn(j, a[i].size()) 
			cout << a[i][j] << ' ';
		cout << endl;
	}

    return 0;
}