#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int n, m, k, p, a[1111][1111], ans=1, d[1111], e[1111];
long long b[1111111], c[1111111], ans1, ans2, anstask=-1000000000000000;

int main() {
	cin >> n >> m >> k >> p;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &a[i][j]);
	priority_queue<long long> q1, q2;
	for (int i=0; i<n; i++) {
		int sum=0;
		for (int j=0; j<m; j++) {
			sum+=a[i][j];
		}
		d[i]=sum;
	}
	for (int i=0; i<m; i++) {
		int sum=0;
		for (int j=0; j<n; j++) {
			sum+=a[j][i];
		}
		e[i]=sum;
	}
	for (int i=0; i<n; i++) q1.push(d[i]);
	for (int i=0; i<=k; i++) {
		b[i]=ans1;
		long long cc=q1.top();
		ans1+=cc;
		q1.pop();
		q1.push(cc-p*m);
	}
	for (int i=0; i<m; i++) q2.push(e[i]);
	for (int i=0; i<=k; i++) {
		c[i]=ans2;
		long long cc=q2.top();
		ans2+=cc;
		q2.pop();
		q2.push(cc-p*n);
	}
	for (int i=0; i<=k; i++) {
		anstask=max(anstask, b[i]+c[k-i]-((long long)i*p)*(k-i));
	}
	cout << anstask;
    return 0;
}