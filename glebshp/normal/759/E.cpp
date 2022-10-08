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

const long long base = 1000 * 1000 * 1000;
const int baselen = 9;
const int mdl = 1000 * 1000 * 1000 + 7;
const int size = 1000 * 1000 + 100;

long long num[size];
long long nnum[size];
int a[size];
int b[size];
int c[size];
int dp[size];
int ndp[size];
int n;
char buf[size];

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
    	scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    	scanf("%d", &b[i]);
    a[n - 1] = base;
    b[n] = 0;
    n++;

    scanf("%s", buf);
    int slen = strlen(buf);
    reverse(buf, buf + slen);
    int len = (slen + baselen - 1) / baselen;
	for (int i = 0; i < len; i++) {
		for (int j = min(slen, (i + 1) * baselen) - 1; j >= i * baselen; j--) {
			num[i] = num[i] * 10 + (buf[j] - '0');
		}

//		cerr << i << ' ' << num[i] << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 1) {
			c[i] = 0;
			continue;
		}

		long long rem = 0ll;
		for (int j = len - 1; j >= 0; j--) {			
			num[j] = (num[j] + rem * base);
			rem = num[j] % a[i];
			num[j] /= a[i];
		}	

		c[i] = rem;
	//			cerr << i << ' ' << c[i] << ' ' << num[0] << endl;

		while (len > 0 && num[len - 1] == 0)
			len--;
	}

//	cerr << "here" << endl;

	if (len > 0) {
		cout << 0 << endl;

		return 0;
	}

	int curlen = 0;
	dp[0] = 1;

    for (int i = 0; i < n - 1; i++) {
    	int cum = 0;
    	for (int j = curlen + 1; j <= curlen + b[i]; j++)
    		dp[j] = 0;
    	curlen += b[i];
    	for (int j = 0; j <= curlen; j++) {
    		cum += dp[j];
    		if (cum >= mdl)
    			cum -= mdl;
    		if (j - b[i] - 1 >= 0) {
    			cum += mdl - dp[j - b[i] - 1];
    			if (cum >= mdl)
    				cum -= mdl;
    		}
    		ndp[j] = cum;
    	}

    	if (a[i] == 1) {
    		for (int j = 0; j <= curlen; j++)
    			dp[j] = ndp[j];
    	} else {
	    	int hlen = 0;
    		if (curlen >= c[i]) {
    			dp[0] = ndp[c[i]];
	    	} else {
    			dp[0] = 0;
    		}
    		while (curlen + 0ll >= c[i] + a[i] * 1ll * (hlen + 1)) {
//    			cerr << hlen << endl;
    			dp[hlen + 1] = ndp[c[i] + a[i] * (hlen + 1)];
    			hlen++;	
    		}

    		curlen = hlen;
    	}    

    //	for (int j = 0; j <= curlen; j++) {
    //		cerr << i << ' ' << j << ' ' << dp[j] << endl;
    //	}
    }

    /*
    if (curlen < c[n - 1])
    	cout << 0 << endl;
    else
    	cout << dp[c[n - 1]] << endl;
    */
    cout << dp[0] << endl;

    return 0;
}