#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define fi first
#define se second
typedef pair<int,int> PII;
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, n-1)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef unsigned int UL;
#define PB push_back

int a[2222];
int n;

int main() {
	scanf("%d", &n);
	forint(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i]<0) a[i]=-a[i];
	}
	int ans=0;
	forint(i, 1, n) {
		int cl=0, cr=0;
		forint(j, 1, i-1) if(a[j]<a[i]) ++cl;
		forint(j, i+1, n) if(a[j]<a[i]) ++cr;
		ans+=min(cl, cr);
	}
	printf("%d\n", ans);

	return 0;
}