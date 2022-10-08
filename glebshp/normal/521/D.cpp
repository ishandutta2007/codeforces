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

int n, m, k;

vector <int> usedeq;
vector <int> usedadd;
vector <int> usedmult;

vector <pair <long long, int> > addme[size];
vector <pair <long long, int> > eqme[size];
long long a[size];
long long b[size];
int tp[size];
int tg[size];

long long nod(long long a, long long b) {
	if (b == 0)
		return a;

	return nod(b, a % b);
}

struct fract {
	long long p, q;

	fract(long long p_ = 0, long long q_ = 1) : p(p_), q(q_) {
		norm();
	}

	void norm() {
		long long d = nod(p, q);
		p /= d;
		q /= d;
	}
};

bool operator < (const fract& a, const fract& b) {
	return a.p * b.q < b.p * a.q;
}

set <pair <fract, int> > allopts;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < k; i++)
    	scanf("%I64d", &a[i]);
    for (int i = 0; i < n; i++) {
    	scanf("%d%d%I64d", &tp[i], &tg[i], &b[i]);
    	tg[i]--;
    	if (tp[i] == 1) {
    		eqme[tg[i]].pb(mp(b[i], i));
    	} 
    	if (tp[i] == 2) {
    		addme[tg[i]].pb(mp(b[i], i));
    	}
    	if (tp[i] == 3) {
    		if (b[i] > 0)
	    		allopts.insert(mp(fract(b[i] - 1, 1), i));
    	}
    }

    for (int i = 0; i < k; i++) {
    	sort(eqme[i].begin(), eqme[i].end());
    	if (!eqme[i].empty() && eqme[i].back().fs > a[i]) {
    		addme[i].pb(mp(eqme[i].back().fs - a[i], eqme[i].back().sc));
    	}
    }

    for (int i = 0; i < k; i++) {
    	sort(addme[i].begin(), addme[i].end());
    	if (!addme[i].empty()) {
	    	allopts.insert(mp(fract(addme[i].back().fs, a[i]), addme[i].back().sc));

    		addme[i].pop_back();
       	}
    }

    for (int i = 0; i < m; i++) {
    	if (allopts.empty())
    		break;
  		int num = allopts.rbegin()->sc;

  		allopts.erase(*allopts.rbegin());
  		if (tp[num] == 1) {
  			usedeq.pb(num);
  			a[tg[num]] = b[num];
  		}
  		if (tp[num] == 2) {
  			usedadd.pb(num);
  			a[tg[num]] += b[num];
  		}
  		
  		if (tp[num] < 3) {
  			if (!addme[tg[num]].empty()) {
  				allopts.insert(mp(fract(addme[tg[num]].back().fs, a[tg[num]]), addme[tg[num]].back().sc));
  				addme[tg[num]].pop_back();
  			}
  		}

  		if (tp[num] == 3) {
  			usedmult.pb(num);
  		}
    }

    int as = (int) usedeq.size() + (int) usedadd.size() + (int) usedmult.size();

    printf("%d\n", as);

    assert(as <= m);

    for (int i = 0; i < (int) usedeq.size(); i++)
    	printf("%d ", usedeq[i] + 1);
    for (int i = 0; i < (int) usedadd.size(); i++)
    	printf("%d ", usedadd[i] + 1);
    for (int i = 0; i < (int) usedmult.size(); i++)
    	printf("%d ", usedmult[i] + 1);



    return 0;
}