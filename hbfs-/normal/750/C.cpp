#include <iostream>
#include <cstdio>

#define N 200050

using namespace std;
typedef long long LL;
int n,k,p,t,c[N];
int v[N];

bool go(LL x) {
	for (int i=1;i<=n;i++) {
		if (x >= 1900 && c[i] == 2) return false;
		x += 1LL*v[i];
	}
	return true;
}

bool div1(LL x) {
	for (int i=1;i<=n;i++) {
		if (x < 1900 && c[i] == 1) return false;
		x += 1LL*v[i];
	}
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
		scanf("%d%d",&v[i],&c[i]);
	LL l = -(1LL<<29) , r = (1LL<<29);
	while (l<r) {
		LL mid = (l + r + 1) >> 1;
		if (go(mid)) l = mid; else r = mid - 1;
	}
	
	if (!div1(l)) {
		puts("Impossible"); return 0;
	}
	if (r == (1LL<<29)) puts("Infinity");
		else {
			for (int i=1;i<=n;i++) l += 1LL*v[i];
			cout << l << endl;
		}
	return 0;
}