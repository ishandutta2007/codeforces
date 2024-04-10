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
const long long mdl = 1000 * 1000 * 1000 + 7;

long long msk[10];
long long len[10];
string str;
vector <pair <int, string> > ops;
int n;

long long fpw(long long a, long long b) {
	if (b == 0)
		return 1;
	long long d = fpw(a, b / 2);
	d = (d * d) % mdl;
	if (b & 1) {
		d = (d * a) % mdl;
	}

	return d;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    cin >> str;
    cin >> n;
    string cur;
    ops.pb(mp(0, str));
    for (int i = 0; i < n; i++) {
    	cin >> cur;
    	ops.pb(mp(cur[0] - '0', string(cur.begin() + 3, cur.end())));
    }

    for (int i = 0; i < 10; i++) {
    	msk[i] = i;
    	len[i] = 1;
    }
    for (int i = n; i >= 0; i--) {
    	long long res = 0;
    	long long h = 0;
    	for (int j = (int) ops[i].sc.size() - 1; j >= 0; j--) {
    		res = (res + msk[ops[i].sc[j] - '0'] * fpw(10, h)) % mdl;
    		h = (h + len[ops[i].sc[j] - '0']) % (mdl - 1);
    	}
    	msk[ops[i].fs] = res;
    	len[ops[i].fs] = h;
    }

    cout << msk[0] << endl;

    return 0;
}