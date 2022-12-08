#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn],b[maxn],x[1000010],y[1000010],cnt;
int cmp(int x,int y) {
	return a[x]==a[y]?x<y:a[x]<a[y];
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i;j++)
			if(b[j]>b[j+1]) {
				swap(b[j],b[j+1]);
				x[++cnt]=b[j];
				y[cnt]=b[j+1];
			}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}