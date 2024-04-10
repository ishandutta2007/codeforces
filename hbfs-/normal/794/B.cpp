#include <bits/stdc++.h>
using namespace std;
typedef double db;
inline int rd() {int r;scanf("%d",&r);return r;}
db n,h;
db S;
int main() {
	n = rd(), h = rd();
	S = h / 2;
	db x = 0;
	for (int i=1;i<n;i++) {
		x += S / (db)n;
		printf("%.12lf%c",sqrt(2*(db)x/h) * h,i==n-1?'\n':' ');
	}
	return 0;
}