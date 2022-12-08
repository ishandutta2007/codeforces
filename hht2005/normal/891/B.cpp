#include<bits/stdc++.h>
using namespace std;
const int N=30;
int a[N],p[N],b[30];
int cmp(int x,int y) {
	return a[x]<a[y];
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<n;i++)
		b[p[i]]=a[p[i+1]];
	b[p[n]]=a[p[1]];
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	puts("");
	return 0;
}