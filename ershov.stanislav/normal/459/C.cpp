#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=111;
#endif

long long n, k, d, p=1, c[1111][1111];
bool ans;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k >> d;
	for (int i=0; i<d; i++) {
		p*=k;
		if (p>=n) {
			ans=true;
			break;
		}
	}
	if (ans) {
		for (int i=0; i<d; i++) c[i][0]=1;
		for (int i=1; i<n; i++) {
			for (int j=0; j<d; j++) c[j][i]=c[j][i-1];
			c[0][i]++;
			for (int j=0; j<d; j++) {
				if (c[j][i]>k) c[j][i]-=k, c[j+1][i]++;
				else break;
			}
		}
		for (int i=0; i<d; i++) {
			for (int j=0; j<n; j++) cout << c[i][j] << ' ';
			cout << endl;
		}
	} else cout << -1;
	return 0;
}