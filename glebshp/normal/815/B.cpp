#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long long mdl = 1000 * 1000 * 1000 + 7;

long long pwr(long long a, long long b) {
	if (b == 0)
		return 1ll;
	long long d = pwr(a, b / 2);
	d = (d * d) % mdl;
	if (b & 1)
		d = (d * a) % mdl;

	return d;
}

long long back(long long a) {
	return pwr(a, mdl - 2);
}

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    

    vector <long long> a(n, 0ll);
    for (int i = 0; i < n; i++)
    	scanf("%lld", &a[i]);
    
    int cur = 0;
    while (a.size() > 1 && ((int) a.size() % 2 != 0 || cur != 0)) {
    	vector <long long> b;
    	for (int i = 0; i < (int) a.size() - 1; i++) {
    		if (!cur) {
    			b.pb((a[i] + a[i + 1]) % mdl);
    		} else {
    			b.pb((a[i] - a[i + 1] + mdl) % mdl);
    		}
    		cur ^= 1;
    	}

    	a = b;
    }

//    cerr << a.size() << endl;

    if ((int) a.size() == 1) {
    	printf("%lld", a[0]);

    	return 0;
    }

  //  for (auto& e : a) {
    //	cerr << e << ' ';
   // }
   // cerr << endl;

    if ((int) a.size() % 4 == 0) {
    	long long ans = 0ll;
    	long long cur = 1ll;
    	int n = (int) a.size() / 2 - 1;
    	for (int i = 0; i <= n; i++) {
    //		cerr << a[2 * i] << ' ' << a[2 * i + 1] << ' ' << cur << endl;
    		ans += a[2 * i] * cur;
    		ans -= a[2 * i + 1] * cur;
    		ans %= mdl;
    		ans = (ans + mdl) % mdl;

    		if (i < n) {
	    		cur = (cur * (n - i)) % mdl;
    			cur = (cur * back(i + 1)) % mdl;
    		}
    //		cerr << i << ' ' << cur << endl;
    	}

    	printf("%lld\n", ans);
    } else {
    	long long ans = 0ll;
    	long long cur = 1ll;
    	int n = (int) a.size() / 2 - 1;
    	for (int i = 0; i <= n; i++) {
    		ans += a[2 * i] * cur;
    		ans += a[2 * i + 1] * cur;
    		ans %= mdl;
    		ans = (ans + mdl) % mdl;

    		if (i < n) {
	    		cur = (cur * (n - i)) % mdl;
    			cur = (cur * back(i + 1)) % mdl;
    		}
    	}

    	printf("%lld\n", ans);    
    }

    return 0;
}