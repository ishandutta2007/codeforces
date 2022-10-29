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
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 101000;

string s;
int i, j, n;
int a[30];

int main() {

	//freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	
	cin >> s;
	n = s.size();
	forn(ii, n) 
		a[int(s[ii] - 'a')]++;

	i = 0;
	while (i < n) {
		j = 29;
		while (j > 0 && a[j] == 0) j--;
		while (i < n && int(s[i] - 'a') != j) {
			a[int(s[i] - 'a')]--;
			i++;
		}

		if (i < n) {
			a[j]--;
			i++;
			cout << char('a' + j);
		}
	}

	return 0;
}