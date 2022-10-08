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
const int size = 500 * 1000;
const int inf = 1000 * 1000 * 1000;

unsigned long long msk1[size];
unsigned long long msk2[size];

int dst[size][4];
int n, m, k;
int lst[4];

char s[size], t[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    scanf("%s", s);
    scanf("%s", t);

//    cerr << s << ' ' << t << endl;

    lst[0] = lst[1] = lst[2] = lst[3] = inf;

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4; j++)
    		lst[j]++;
    	if (s[i] == 'A')
    		lst[0] = 0;
    	if (s[i] == 'C')
    		lst[1] = 0;
        if (s[i] == 'G')
    		lst[2] = 0;
        if (s[i] == 'T')
    		lst[3] = 0;

    	for (int j = 0; j < 4; j++)
    		dst[i][j] = lst[j];
    }

    lst[0] = lst[1] = lst[2] = lst[3] = inf;

    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j < 4; j++)
    		lst[j]++;
    	if (s[i] == 'A')
    		lst[0] = 0;
    	if (s[i] == 'C')
    		lst[1] = 0;
        if (s[i] == 'G')
    		lst[2] = 0;
        if (s[i] == 'T')
    		lst[3] = 0;

    	for (int j = 0; j < 4; j++)
    		dst[i][j] = min(dst[i][j], lst[j]);
    }

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < 4; j++) {
    		if (dst[i][j] <= k) {
    			msk1[(i / 16)] |= (1ull << ((i % 16) * 4 + j));
//    			cerr << i << ' ' << j << endl;
    		}	
    	}

    for (int i = 0; i < m; i++) {
    	int h = -1;
   		if (t[i] == 'A')
    		h = 0;
    	if (t[i] == 'C')
			h = 1;
        if (t[i] == 'G')
    		h = 2;
        if (t[i] == 'T')
    		h = 3;

    	msk2[(i / 16)] |= (1ull << ((i % 16) * 4 + h));
//    	cerr << i << ' ' << h << endl;
    }

    int ans = 0;
    int mylen = (m + 15) / 16;
    for (int i = 0; i < 16; i++) {
//    	cerr << i << ' ' << ans << endl;
    	for (int j = 0; j < n - m - i + 1; j += 16) {
			int ps = j / 16;
			ans++;
			for (int p = 0; p < mylen; p++)
				if ((msk1[ps + p] & msk2[p]) ^ msk2[p]) {
					ans--;
					break;
				}    		
    	}
    	for (int j = 0; j < (n + 15) / 16; j++) {
    		msk1[j] = (msk1[j] >> 4) | (msk1[j + 1] << 60);
    	}
    }

    cout << ans << endl;
    
    return 0;
}