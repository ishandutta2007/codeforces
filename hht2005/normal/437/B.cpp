#include<bits/stdc++.h>
using namespace std;
int t[100000],cnt,a[100010];
inline int cmp(int x,int y) {
	return (x&-x)<(y&-y);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)a[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=m;i>=1;i--)
		if(n>=(a[i]&-a[i]))t[++cnt]=a[i],n-=a[i]&-a[i];
	if(n!=0) {
		puts("-1");
		return 0;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d ",t[i]);
	puts("");
	return 0;
}