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
const int MAXN = 5000;

vector<int64> lucky;
vector<int> perm, fin;
int64 n, k, mm, mf, ans;
int pos, p;

void get(int64 c, int l) {
        if (l != 0)
                lucky.push_back(c);
        if (l < 9) {
                get(c * 10 + 4, l + 1);
                get(c * 10 + 7, l + 1);
        }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	cin >> n >> k;
    get(0, 0);
    sort(all(lucky));
	ans = upper_bound(all(lucky), n) - lucky.begin(); //GUARANTEE - NUM
	pos = ans - 1;

	mm = 1, mf = 1;
	while (mf < k) {
		mm++;
		mf *= mm;
	}
	if (mm > n) {
		cout << -1;
		return 0;
	}
	if (n < 4) {
		cout << 0;
		return 0;
	}
	//cout << lucky[pos];

	for (int i = n - mm + 1; i <= n; i++) {
		perm.push_back(i);
		if (binary_search(all(lucky), perm.back())) ans--;
	}

	k--;
	for (int i = 1; i < mm; i++) {
		mf /= (mm - i + 1);
		p = k / mf;
		fin.push_back(perm[p]);
		for (int j = p; j < mm - i; j++)
			perm[j] = perm[j + 1];
		perm.pop_back();
		k = k % mf;
	}
	fin.push_back(perm[0]);

	forn(i, mm)
		if (binary_search(all(lucky), fin[i]) && binary_search(all(lucky), n - mm + i + 1))
			ans++;
	cout << ans;

    return 0;
}