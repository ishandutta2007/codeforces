#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],p[N],s[N][N];
int cmp(int x,int y) {
	return a[x]>a[y];
}
int main() {
	int n,Max=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=i,k=1;k<=a[p[i]];k++,j=j%(n+1)+1)
			s[j][p[i]]=1,Max=max(Max,j);
	printf("%d\n",Max);
	for(int i=1;i<=Max;i++) {
		for(int j=1;j<=n;j++)
			printf("%d",s[i][j]);
		puts("");
	}
	return 0;
}