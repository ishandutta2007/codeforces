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

int n, a;
unsigned long long p[333333], h1[333333], h2[333333];

void add(unsigned long long a[], unsigned long long d, int i) {
	for (; i<333333; i|=(i+1)) a[i]+=d;
}

unsigned long long getsum(unsigned long long a[], int i) {
	unsigned long long ans=0;
	for (; i>=0; i=(i&(i+1))-1) ans+=a[i];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (unsigned long long i=0, pp=1; i<333333; i++, pp*=37) p[i]=pp;
	for (int i=0; i<n; i++) {
		scanf("%d", &a);
		if (a<=n/2&&!(getsum(h1, 2*a-1)*p[n-2*a+1]==getsum(h2, n)-getsum(h2, n-2*a+1))) {
			cout << "YES";
			return 0;
		}
		if (a>n/2&&!(getsum(h2, 2*(n+1-a)-1)*p[n-2*(n+1-a)+1]==getsum(h1, n)-getsum(h1, n-2*(n+1-a)+1))) {
			cout << "YES";
			return 0;
		}
		add(h1, p[a], a);
		add(h2, p[n+1-a], n+1-a);
	}
	cout << "NO";
	return 0;
}