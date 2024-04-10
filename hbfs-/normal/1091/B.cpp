#include <bits/stdc++.h>
#define N 1000500
using namespace std;
typedef long long LL;
inline int rd() {int r;scanf("%d",&r);return r;}
long long n,x,y;
int main() {
	n = rd();
	for (int _=1;_<=2*n;_++) {
		x += rd(), y += rd();
	}
	cout << x/n << " " << y/n << endl;
	return 0;
}