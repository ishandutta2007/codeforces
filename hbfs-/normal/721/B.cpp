#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 1050

using namespace std;

int n,k,dest;
int a[N];
char s[N];

inline int calc(int x) {
	return x + ( (x-1) /k) * 5;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		a[ strlen(s+1) ]++;
	}
	
	for (int i=1;i<=1000;i++) a[i] += a[i-1];
	
	scanf("%s",s+1);
	dest = strlen(s+1);
	
	int l = a[ dest-1 ] + 1 , r = a[dest];
	
	l = calc(l);
	r = calc(r);
	
	printf("%d %d\n",l,r);
	return 0;
}