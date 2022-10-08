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
#define taskname "task_c"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

int ans[size];
int lbsong[size], rbsong[size];
int lbactor[size], rbactor[size], k[size];
int n, m;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &lbsong[i], &rbsong[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &lbactor[i], &rbactor[i], &k[i]);
	}

	vector <pair <int, int> > songs;
	vector <pair <int, int> > actors;
	for (int i = 0; i < n; i++)
		songs.pb(mp(rbsong[i], i));
	for (int i = 0; i < m; i++)
		actors.pb(mp(rbactor[i], i));

	sort(songs.begin(), songs.end());
	sort(actors.begin(), actors.end());

	set <pair <int, int> > opensongs;

	int p = 0;
	for (int i = 0; i < m; i++) {
		while (p < n && songs[p].fs <= actors[i].fs) {
			int num = songs[p].sc;
			opensongs.insert(mp(-lbsong[num], num));
			p++;
		}
		int num = actors[i].sc;
		int level = -lbactor[num];
		while (k[num] > 0) {
			if (opensongs.empty() || opensongs.begin()->fs > level)
				break;
			k[num]--;

			set <pair <int, int> >::iterator it = opensongs.lower_bound(mp(level, -1));
			if (it == opensongs.end() || it->fs > level)
				--it;

			ans[it->sc] = num;
			opensongs.erase(*it);
		}
	}

	if (opensongs.empty() && p == n) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
	} else {
		printf("NO\n");
	}

	return 0;
}