#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 300050
using namespace std;
typedef long long LL;
LL ans;
int tot;
int a,b,c,m;
char type[10]; int tmp;
struct Monster{
	int a,b;
}x[N];
bool cmp(Monster p1,Monster p2) { return p1.a < p2.a; }
int main() {
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%s",&tmp,type+1);
		if (type[1] =='U') 
			x[i].a = tmp , x[i].b = 1;
		else
			x[i].a = tmp , x[i].b = 2;
	}
	sort(x+1,x+m+1,cmp);
	for (int i=1;i<=m;i++) {
		if (x[i].b == 1 && a) { 
			a--; ans += x[i].a; tot++; continue;
		} 
		if (x[i].b == 2 && b) {
			b--; ans += x[i].a; tot++; continue;
		}
		if (c) {
			c--; ans += x[i].a; tot++; continue;
		}
	}
	cout << tot << " " << ans << endl;
	return 0;
}