#include <bits/stdc++.h>
#define N 1000500
using namespace std;
int a[N],b[N],e[N],o[N],n;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(int p1,int p2) {
	return b[p1] < b[p2];
}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=1;i<=n;i++) b[i] = rd();
	for (int i=1;i<=n;i++) e[i] = i;
	sort(a+1,a+n+1);
	sort(e+1,e+n+1,cmp);
	for (int i=1;i<=n;i++) o[ e[i] ] = a[n-i+1];
	for (int i=1;i<=n;i++) printf("%d%c",o[i],i==n?'\n':' ');
	
	return 0;
}