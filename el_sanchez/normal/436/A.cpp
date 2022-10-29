#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;   
const ld eps = 1e-6;
const ld pi = acos(-1.0);
const int MAXN = 2222;   
const ll MOD = 1E9 + 7;

int n, x, cur, ans, val, h;
vector<pair<pii, int> > a;
set<pii> w[2];
pii t;

int main() {

	cin >> n >> x;
	a.resize(n);
	forn(i, n) {
		cin >> a[i].Y >> a[i].X.X >> a[i].X.Y;
    }   
    sort(all(a));

    ans = 0;
    for (int s = 0; s < 2; s++) {
  		cur = s;
  		val = 0;  	
  		h = x;
  		
  		int k = 0;
  		w[0].clear();
  		w[1].clear();

  		while (true) {
    		while (k < n && a[k].X.X <= h) {
    			w[a[k].Y].insert(mp(-a[k].X.Y, k));
    			k++; 
       		}

    		if (!w[cur].empty()) {
    			t = *w[cur].begin();
    			w[cur].erase(t);
    			h -= t.X;
    			val++;
    			cur = 1 - cur;
    		} else {
    			ans = max(ans, val);
    			break;
    		}
    	}

    }

    cout << ans;

	return 0;
}