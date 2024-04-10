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
#include <queue>
#include <ctime>

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
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100000;

string s, p;
int l[2], vp, ans, cur;
int bal[30], need[30];
bool fail;

int main() {

	cin >> s;
	l[0] = s.size();
	cin >> p;
	l[1] = p.size();

	if (l[1] > l[0]) {
		cout << 0;
		return 0;
	}

	ans = 0;
	vp = 0;
	forn(i, l[1] - 1) {
		if (s[i] == '?')
			vp++;
		else
			bal[s[i] - 'a']++;
	}
	forn(i, l[1])
		need[p[i] - 'a']++;

	for (int i = l[1] - 1; i < l[0]; i++) {
		if (s[i] == '?')
			vp++;
		else
			bal[s[i] - 'a']++;

		cur = 0;
		fail = 0;
		forn(j, 26) {
			if (bal[j] > need[j]) {
				fail = 1;
				break;
			} else
				cur += need[j] - bal[j];
		}
		if (!fail && vp >= cur)
			ans++;

		if (s[i - l[1] + 1] == '?')
			vp--;
		else
			bal[s[i - l[1] + 1] - 'a']--;
	}

	cout << ans << endl;

    return 0;
}