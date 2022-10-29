#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cassert>


using namespace std;


#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;  //!!
const ld eps = 1e-7;  //!!
            
int n, k, sum[2], step, id;
vector<vi> s;
vi ptr[2];
vi cntr;
set<pii> p1, p2;
set<pii> pp1, pp2;

int main() {
		
	cin >> n;
	step = 0;
	s.resize(n);
	ptr[0].resize(n);
	ptr[1].resize(n);
	sum[0] = sum[1] = 0;
	cntr.resize(n);
	forn(i, n) {
		cin >> k;
		s[i].resize(k);
		forn(j, k)
			cin >> s[i][j];
		ptr[0][i] = 0;
		ptr[1][i] = k - 1;
		step += k;
	}

	forn(i, n)
		if ((ptr[1][i] - ptr[0][i]) % 2 == 0) {
			p1.insert(mp(-s[i][(ptr[1][i] + ptr[0][i]) / 2], i));
			//p1.insert(mp(-s[i][(ptr[1][i] + ptr[0][i]) / 2], i));
		}

	forn(i, n) {
		pp1.insert(mp(-s[i][0], i));
		pp2.insert(mp(-s[i].back(), i));	
	}

	id = 0;
	while (step) {
	    if (!p1.empty()) {
	    	pii p = *p1.begin();
	    	p1.erase(p);
	    	int sid = p.ss;
	    	if (id == 0) {
	    		sum[id] += s[sid][ptr[0][sid]];
	    		pp1.erase(mp(-s[sid][ptr[0][sid]], sid));
	    		ptr[0][sid]++;
	    		if (ptr[0][sid] <= ptr[1][sid])
	    			pp1.insert(mp(-s[sid][ptr[0][sid]], sid));
	    		else
	    			pp2.erase(mp(-s[sid][ptr[1][sid]], sid));
	    	} else {
	    		sum[id] += s[sid][ptr[1][sid]];
	    		pp2.erase(mp(-s[sid][ptr[1][sid]], sid));
	    		ptr[1][sid]--;
	    		if (ptr[0][sid] <= ptr[1][sid])
	    			pp2.insert(mp(-s[sid][ptr[1][sid]], sid)); 
	    		else
	    			pp1.erase(mp(-s[sid][ptr[0][sid]], sid));	    	
	    	}
	    } else {
	        if (id == 0) {
	        	pii p = *pp1.begin();
	        	int sid = p.ss;
	        	sum[id] += s[sid][ptr[0][sid]];
	    		pp1.erase(mp(-s[sid][ptr[0][sid]], sid));
	    		ptr[0][sid]++;
	    		if (ptr[0][sid] <= ptr[1][sid]) {
	    			pp1.insert(mp(-s[sid][ptr[0][sid]], sid));
	    	        p1.insert(mp(-s[sid][(ptr[1][sid] + ptr[0][sid]) / 2], sid));
				} else
	    			pp2.erase(mp(-s[sid][ptr[1][sid]], sid));

	        } else {
	        	pii p = *pp1.begin();
	        	int sid = p.ss;
	        	sum[id] += s[sid][ptr[1][sid]];
	    		pp2.erase(mp(-s[sid][ptr[1][sid]], sid));
	    		ptr[1][sid]--;
	    		if (ptr[0][sid] <= ptr[1][sid]) {
	    			pp2.insert(mp(-s[sid][ptr[1][sid]], sid));
	    	        p1.insert(mp(-s[sid][(ptr[1][sid] + ptr[0][sid]) / 2], sid));
				} else
	    			pp1.erase(mp(-s[sid][ptr[0][sid]], sid));       
	        }
	    }

	    step--;
		id = 1 - id;
	}

	cout << sum[0] << ' ' << sum[1];

             
    return 0;
}