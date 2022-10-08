#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const int rms = (1 << 21) - 1;
const int hrms = rms / 2;

int rmq[rms + 1];
int lb[size], rb[size], a[size], b[size], c[size];
int longest[size];
int n, m;

vector <int> adopen[size];
vector <int> adclose[size];
vector <int> tvopen[size];
vector <int> tvclose[size];

void change(int ps, int val) {
	ps += hrms + 1;
	rmq[ps] = max(rmq[ps], val);
	while (ps > 1) {
		ps /= 2;
		rmq[ps] = max(rmq[ps * 2], rmq[ps * 2 + 1]);
	}
}

int rss(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i) {
		return 0;
	}
   	if (lb >= i && rb <= j) {
   		return rmq[v];
   	}

   	return max(rss(v * 2, lb, (lb + rb) / 2, i, j), rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j));
}

int main() {

//    freopen("input.txt", "w", stdout);
    /*
    int n = 200 * 1000;
    int m = 200 * 1000;
    int C = 1000 * 1000 * 1000;
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; i++) {
    	int lb = (rand()) % C;
    	int rb = (rand()) % C;
    	if (lb > rb)
    		swap(lb, rb);
    	cout << lb << ' ' << rb << endl;
    }

    for (int i = 0; i < m; i++) {
    	int lb = (rand()) % C;
    	int rb = (rand()) % C;
    	if (lb > rb)
    		swap(lb, rb);
    	cout << lb << ' ' << rb << ' ' << rand() % C + 1 << endl;
    }

  
    return 0;
    */
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector <int> moms;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &lb[i], &rb[i]);
    	moms.pb(lb[i]);
    	moms.pb(rb[i]);
    }
    for (int i = 0; i < m; i++) {
    	scanf("%d%d%d", &a[i], &b[i], &c[i]);
    	moms.pb(a[i]);
    	moms.pb(b[i]);
    }

	sort(moms.begin(), moms.end());
	moms.resize(unique(moms.begin(), moms.end()) - moms.begin());

	for (int i = 0; i < n; i++) {
		lb[i] = lower_bound(moms.begin(), moms.end(), lb[i]) - moms.begin();
		rb[i] = lower_bound(moms.begin(), moms.end(), rb[i]) - moms.begin();

		adopen[lb[i]].pb(i);
		adclose[rb[i]].pb(i);
	}

	for (int i = 0; i < m; i++) {
		a[i] = lower_bound(moms.begin(), moms.end(), a[i]) - moms.begin();
		b[i] = lower_bound(moms.begin(), moms.end(), b[i]) - moms.begin();

		tvopen[a[i]].pb(i);
		tvclose[b[i]].pb(i);
	}

	set <pair <int, int> > leftend;
	set <pair <int, int> > rightend;

	for (int i = 0; i < m; i++) {
		longest[i] = 0;
	}

	for (int i = 0; i < (int) moms.size(); i++) {
		for (int j = 0; j < (int) tvopen[i].size(); j++) {
			int cur = tvopen[i][j];

			if (!rightend.empty())
				longest[cur] = max(longest[cur], moms[rightend.rbegin()->fs] - moms[i]);
		}

		for (int j = 0; j < (int) adopen[i].size(); j++) {
			int cur = adopen[i][j];

			leftend.insert(mp(lb[cur], cur));
			rightend.insert(mp(rb[cur], cur));
		}

		for (int j = 0; j < (int) adclose[i].size(); j++) {
			int cur = adclose[i][j];

			leftend.erase(mp(lb[cur], cur));
			rightend.erase(mp(rb[cur], cur));

			change(lb[cur], moms[rb[cur]] - moms[lb[cur]]);
		}

		for (int j = 0; j < (int) tvclose[i].size(); j++) {
			int cur = tvclose[i][j];

			if (!leftend.empty()) {
				longest[cur] = max(longest[cur], moms[i] - moms[leftend.begin()->fs]);
			}
			longest[cur] = max(longest[cur], rss(1, 1, hrms + 1, a[cur] + 1, b[cur] + 1));
		}
	}

	for (int i = 0; i < m; i++)
		longest[i] = min(longest[i], moms[b[i]] - moms[a[i]]);

	long long ans = 0;
	int best = -1;
	for (int i = 0; i < m; i++) {
		//cerr << i << ' ' << longest[i] << endl;
		if (longest[i] * 1ll * c[i] > ans) {
			ans = longest[i] * 1ll * c[i];
			best = i;
		}
	}

	if (ans == 0) {
		cout << 0 << endl;
	} else {
		cout << ans << endl;

		for (int i = 0; i < n; i++) {
			if ((moms[min(b[best], rb[i])] - moms[max(a[best], lb[i])]) == longest[best]) {
				cout << i + 1 << ' ' << best + 1 << endl;
		//		cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;


				
				return 0;
			}
		}

		//assert(false);
	}

return 0;
}