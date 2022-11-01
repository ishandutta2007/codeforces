#include <bits/stdc++.h>
#define N 1000050
using namespace std;
int n,a,b,x[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	rd(), a = rd(), b = rd();
	n = rd();
	for (int i=1;i<=n;i++) x[i] = rd();
	sort(x+1,x+n+1);
	int l = (int)(upper_bound(x+1,x+n+1,a) - x);
	int r = (int)(upper_bound(x+1,x+n+1,b-1) - x) - 1;
	cout << r - l + 1 << endl;
	return 0;
}