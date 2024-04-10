#include <bits/stdc++.h>
#define N 1000500
using namespace std;
int n,l,x,y,fx,fy,a[N];
map<int,int> mp;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), l = rd(), x = rd(), y = rd();
	for (int _=1;_<=n;_++) a[_] = rd();
	
	for (int _=1;_<=n;_++) {
		mp[ a[_] ] = 1;
		if (mp[ a[_]-x ]) fx = 1;
		if (mp[ a[_]-y ]) fy = 1;
	}
	
	if (fx && fy) return puts("0"), 0;
	if (fx) return printf("1\n%d\n",y), 0;
	if (fy) return printf("1\n%d\n",x), 0;
	
	mp.clear();
	for (int _=1;_<=n;_++) {
		mp[ a[_] ] = 1;
		if (mp[ a[_]-x-y ])
			return printf("1\n%d\n",a[_]-x), 0;
		if (a[_]-y>=0 && mp[ a[_]-y+x ])
			return printf("1\n%d\n",a[_]-y), 0;
		if (a[_]+x<=l && mp[ a[_]-y+x ])
			return printf("1\n%d\n",a[_]+x), 0;
	}
	printf("2\n%d %d\n",x,y);
	
	return 0;
}