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

int p[3333];
int n;

/*
	f[0]=0
	f[1]=1
	f[i]=4+f[i]+f[i-2]
*/

int main() {
	scanf("%d", &n);
	int cur=0;
	forint(i, 1, n) {
		scanf("%d", &p[i]);
		forint(j, 1, i-1) {
			if(p[j]>p[i]) ++cur;
		}
	}
	if(n==1) {
		printf("0\n");
		return 0;
	}
	if(n==2) {
		printf("%d\n", cur);
		return 0;
	}
	int t=4*(cur/2)+cur%2;
	printf("%d\n", t);

	return 0;
}