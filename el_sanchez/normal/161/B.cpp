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
const int MAXN = 2000;

int k, vk, n, p[2], w[2];
vector<pair<double, int> > ans[MAXN], tb, kr;
vi istab;
double cost, ccost, mmm;

int main() {

	cin >> n >> k;
	forn(i, n) {
		cin >> p[0] >> p[1];
		if (p[1] == 1)
			tb.push_back(make_pair(p[0], i));
		else
			kr.push_back(make_pair(p[0], i));
	}
	forn(i, n)
		istab.push_back(0);

	sort(all(tb)); w[0] = tb.size();
	if (k <= w[0]) {
		vk = k;
		forn(i, k) {
			ans[i].push_back(tb.back());
			istab[i] = 1;
			tb.pop_back();
		}
		p[0] = tb.size();
		forn(i, p[0]) {
			kr.push_back(tb.back());
			tb.pop_back();
		}
	} else {
		vk = tb.size();
		forn(i, vk) {
			ans[i].push_back(tb.back());
			istab[i] = 1;
			tb.pop_back();
		}
	}

	sort(all(kr)); reverse(all(kr)); w[1] = kr.size();
	if (vk != k) {
		forn(i, k - vk) {
			ans[vk + i].push_back(kr.back());
			kr.pop_back();
		}
	}
	reverse(all(kr));

	p[0] = 0, w[0] = kr.size();
	while (p[0] < vk && w[0] > 0) {
		if (ans[p[0]][0].fi <= kr.back().fi) {
			ans[p[0]].push_back(kr.back());
			kr.pop_back();
			p[0]++;
		} else {
			ans[k - 1].push_back(kr.back());
			kr.pop_back();
		}
		w[0]--;
	}
	while (w[0] > 0) {
		ans[k - 1].push_back(kr.back());
		kr.pop_back();
		w[0]--;
	}

	cost = 0;
	forn(i, k) {
		ccost = 0;
		mmm = INF + 100500;
		forn(j, ans[i].size()) {
			ccost += ans[i][j].first;
			if (mmm > ans[i][j].first)
				mmm = ans[i][j].first; 
		}
		if (istab[i]) 
			ccost -= mmm / 2;
		cost += ccost;
	}

	printf("%.1f\n", (cost + 0.001));
	forn(i, k) {
		cout << ans[i].size();
		forn(j, ans[i].size()) 
			cout << ' ' << ans[i][j].se + 1;
		cout << endl;
	}

    return 0;
}