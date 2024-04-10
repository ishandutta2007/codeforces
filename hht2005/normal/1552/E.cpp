#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int c[N],p[N],x[N],y[N],las[N],t[N];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++) {
		scanf("%d",c+i);
		las[i]=t[c[i]];
		t[c[i]]=i;
	}
	for(int i=1;i<=n;i+=(k-1)) {
		int m=0,R=0;
		for(int j=1;j<=n*k;j++)
			if(i<=c[j]&&c[j]<=i+k-2)
				p[++m]=j;
		for(int j=1;j<=m;j++) {
			if(las[p[j]]>R&&!x[c[p[j]]]) {
				x[c[p[j]]]=las[p[j]];
				y[c[p[j]]]=p[j];
				R=p[j];
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}