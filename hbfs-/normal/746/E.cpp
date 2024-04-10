#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define N 400050

using namespace std;
int cura = -1 , pa = 1 , curb = 0 , pb = 1;
int x[N],y[N],a[N],b[N],cnta,cntb,n,m,ans;
int aska() {
	for (cura+=2;pa<=cnta;cura+=2) {
		while (pa<n && y[ a[pa] ] == y[ a[pa+1] ]) pa++;
		if (cura == y[a[pa]]) pa++; else break;
	}
	return cura;
}
int askb() {
	for (curb+=2;pb<=cntb;curb+=2) {
		while (pb<n && y[ b[pb] ] == y[ b[pb+1] ]) pb++;
		if (curb == y[b[pb]]) pb++; else break;
	}
	return curb;
}
bool cmp(int p1,int p2) { return x[p1] < x[p2]; }

int main()
{
	scanf("%d%d",&n,&m);
	if (n&1) { puts("-1"); return 0; }
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) y[i] = x[i];
	
	for (int i=1;i<=n;i++) 
		if (x[i]&1) a[++cnta] = i; else b[++cntb] = i;
	sort(a+1,a+cnta+1,cmp);
	sort(b+1,b+cntb+1,cmp);
	
	x[0] = -1;
	int c1 = cnta , c2 = cntb;
	for (int i=1;i<=cnta;i++) 
		if (x[a[i]] == x[a[i+1]]) {
			if (c1 > c2) {
				x[ a[i] ] = askb();
				ans++;
				c1--;
				c2++;
			}
			else {
				x[ a[i] ] = aska();
				ans++;
			}
		}
	for (int i=1;i<=cntb;i++) 
		if (x[b[i]] == x[b[i+1]]) {
			if (c2 > c1) {
				x[ b[i] ] = aska();
				ans++;
				c1++;
				c2--;
			}
			else {
				x[ b[i] ] = askb();
				ans++;
			}
		}
	
	if (c1 > c2) {
		int t = ( c1 - c2 ) / 2 , k = 1;
		ans += t;
		for (int i=1;i<=n,k<=t;i++)
			if (x[i] & 1) x[i] = askb() , k++;
	} else {
		int t = ( c2 - c1 ) / 2 , k = 1;
		ans += t;
		for (int i=1;i<=n,k<=t;i++)
			if ((x[i]&1) == 0) x[i] = aska() , k++;
	}
	if (cura > m || curb > m) { puts("-1"); return 0; }
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d%c",x[i],i==n?'\n':' ');
	return 0;
}