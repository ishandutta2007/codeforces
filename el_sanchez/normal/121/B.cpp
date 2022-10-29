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
const int MAXN = 101000;

int n, k, pos;
string num;
bool f4[MAXN], f7[MAXN];

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	scanf("%d%d\n", &n, &k);
	cin >> num;
	num = '%' + num;
	f4[0] = f7[0] = 0;
	for (int i = 1; i <= n; i++) {
		f4[i] = (num[i] == '4');
		f7[i] = (num[i] == '7');
	}

	pos = 0;
	while (k > 0) {
		while (pos < n && !(f4[pos] && f7[pos + 1])) pos++;
		if (pos == n) break;
		if (pos % 2) {
			if (pos + 2 <= n && f7[pos + 2]) {
				if (k % 2) {
					f7[pos + 1] = 0;
					f4[pos + 1] = 1;
					num[pos + 1] = '4';
				}
				break;
			}
			f7[pos + 1] = 0;
			f4[pos + 1] = 1;
			num[pos + 1] = '4';
			k--;
		} else {
			if (pos > 1 && f4[pos - 1]) {
				if (k % 2) {
					f4[pos] = 0;
					f7[pos] = 1;
					num[pos] = '7';
				}
				break;
			}
			f4[pos] = 0;
			f7[pos] = 1;
			num[pos] = '7';
			k--;
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << num[i];
	cout << endl;

    return 0;
}