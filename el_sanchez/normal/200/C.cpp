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

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 100000;

struct team {
	int pts, goals[2];
	string name;
};

bool compare(team a, team b) {
	if (a.pts != b.pts) return a.pts < b.pts;
	if (a.goals[0] - a.goals[1] != b.goals[0] - b.goals[1]) 
		return a.goals[0] - a.goals[1] < b.goals[0] - b.goals[1];
	if (a.goals[0] != b.goals[0])
		return a.goals[0] < b.goals[0];
	return a.name > b.name;
}

int n, k[2], kn[2];
string s[2], ts;
map<string, int> w;
team a[4], b[4];
int use[4], ans[2];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	n = 0;
	forn(i, 4)
		a[i].pts = a[i].goals[0] = a[i].goals[1] = 0;
	forn(i, 5) {
		cin >> s[0] >> s[1] >> ts;
		forn(i, 2) {
			if (w.find(s[i]) == w.end()) {
				w[s[i]] = n;
				a[n++].name = s[i];
			}
			k[i] = w[s[i]];
			use[k[i]]++;
		}

		if (ts[0] < ts[2]) {
			a[k[1]].pts += 3;
		} else if (ts[0] == ts[2]) {
			a[k[0]].pts += 1;
			a[k[1]].pts += 1;
		} else {
			a[k[0]].pts += 3;
		}
		a[k[0]].goals[0] += (ts[0] - '0');
		a[k[1]].goals[1] += (ts[0] - '0');
		a[k[0]].goals[1] += (ts[2] - '0');
		a[k[1]].goals[0] += (ts[2] - '0');
	}

	sort(a, a + 4, compare);
	forn(i, 4)
		if (a[i].name == "BERLAND")
			k[0] = i;
	forn(i, 4)
		if (use[w[a[i].name]] == 2 && i != k[0])
			k[1] = i;

	ans[0] = ans[1] = INF;
	forn(q1, 50)
		forn(q2, 50) {
			if (q1 <= q2) continue;
			forn(i, 4)
				b[i] = a[i];
			
			b[k[0]].pts += 3;
			b[k[0]].goals[0] += q1;
			b[k[1]].goals[1] += q1;
			b[k[0]].goals[1] += q2;
			b[k[1]].goals[0] += q2;

			sort(b, b + 4, compare);
			if (b[3].name == "BERLAND" || b[2].name == "BERLAND") {
				if ((ans[0] == INF) || (ans[0] - ans[1] > q1 - q2) || (ans[0] - ans[1] == q1 - q2 && ans[1] > q2))
					ans[0] = q1, ans[1] = q2;
			}
		}
	
	if (ans[0] == INF)
		cout << "IMPOSSIBLE";
	else
		cout << ans[0] << ':' << ans[1];

	return 0;
}