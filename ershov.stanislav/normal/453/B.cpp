#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int prime[16] = {2,	3,	5,	7,	11,	13,	17,	19,	23,	29,	31,	37,	41,	43,	47,	53}, masks[70], a1[100000][111], prevv[100000][111], n, a[111];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	for (int i=1; i<59; i++) {
		for (int j=0; j<16; j++) if (!(i%prime[j])) masks[i]|=1<<j;
	}
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	int cnt=1<<16;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<cnt; j++) a1[j][i]=100000;
		for (int j=0; j<cnt; j++) {
			for (int k=1; k<59; k++) if (!(masks[k]&j)) {
				int nn=a1[j][i-1]+abs(k-a[i]);
				if (nn<a1[j|masks[k]][i])a1[j|masks[k]][i]=nn, prevv[j|masks[k]][i]=k;
			}
		}
	}
	int ans=100000, a2=0;
	for (int i=0; i<cnt; i++) if(ans>a1[i][n]) ans=a1[i][n], a2=i;
	vector<int> res;
	for (int i=n; i>=1; i--) {
		res.push_back(prevv[a2][i]);
		a2^=masks[prevv[a2][i]];
	}
	for (int i=n-1; i>=0; i--) cout << res[i] << ' ';
    return 0;
}