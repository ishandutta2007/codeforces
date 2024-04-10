#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	int ans = 0,a,b,c;
	a = rd(), b = rd(), c = rd();
	for (int i=1;i<=100;i++) if (i<=a && i+1<=b && i+2<=c) ans = i+i+1+i+2;
	cout << ans << endl;
	return 0;
}