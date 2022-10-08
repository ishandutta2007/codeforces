#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;

map <pair <int, int>, int> num;
int x[size], y[size];
int n, m;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);

	vector <pair <int, int> > vec;

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--, y[i]--;
		num[mp(x[i],y[i])] = i + 1;

		vec.pb(mp(x[i] + y[i], i));
	}

	sort(vec.begin(), vec.end());
	vector <pair <int, int> > cur;
	cur.pb(mp(0, 0));

	int i = 0;
	int j = 0;
	int lstmom = 0;
	while (i < (int) vec.size()) {
		int curmom = vec[i].fs;
		while (j < (int) vec.size() && vec[i].fs == vec[j].fs)
			j++;
		vector <pair <int, int> > events;
		int mcx, mnc;
		if (curmom <= n - 1) {
			mcx = curmom;
			mnc = 0;
		} else {
			mcx = n - 1;
			mnc = curmom - (n - 1);
		}

		int step = curmom - lstmom;
		
		for (int j = 0; j < (int) cur.size(); j++) {
			events.pb(mp(min(mcx, max(mnc, cur[j].fs)), 0));
			events.pb(mp(min(mcx, max(mnc, cur[j].sc + step)), 2));
		}
		for (int k = i; k < j; k++)
			events.pb(mp((y[vec[k].sc] - x[vec[k].sc] + curmom) / 2, 1));

		sort(events.begin(), events.end());
		int lst = 0;
		int cnt = 0;
		vector <pair <int, int> > ncur;

		for (int k = 0; k < (int) events.size(); k++) {
			if (events[k].sc == 0) {
				cnt++;
				if (cnt == 1)
					lst = events[k].fs;
			}
			if (events[k].sc == 1) {
				if (cnt > 0 && lst < events[k].fs) {
					ncur.pb(mp(lst, events[k].fs - 1));
				}
				lst = events[k].fs + 1;
			}
			if (events[k].sc == 2) {
				cnt--;
				if (cnt == 0 && lst <= events[k].fs) {
					ncur.pb(mp(lst, events[k].fs));
				}
			}
		}

		swap(cur, ncur);

		lstmom = curmom;
		i = j;
	}

	if (cur.empty()) {
		cout << -1 << endl;
	} else {
		cout << 2 * n - 2 << endl;
	}

	return 0;
}