#include <bits/stdc++.h>
#define N 5050
using namespace std;
struct HbFS{int a,b;}Q[N];
bool cmp(HbFS p1, HbFS p2) {return p1.a == p2.a ? p1.b < p2.b : p1.a < p2.a;}
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	int n = rd();
	for (int _=1;_<=n;_++) Q[_].a = rd(), Q[_].b = rd();
	sort(Q+1,Q+n+1,cmp);
	int ans = 0;
	for (int _=1;_<=n;_++)
		if (Q[_].b>=ans) ans = Q[_].b; else ans = Q[_].a;
	cout << ans << endl;
	return 0;
}