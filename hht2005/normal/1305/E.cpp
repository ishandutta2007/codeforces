#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,sum=0,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		if(sum+(i-1)/2<=m)sum+=(i-1)/2;
		else break;
	if(i>n&&sum<m)return puts("-1"),0;
	else {
		for(int j=1;j<i;j++)
			printf("%d ",j);
		if(i>n)return 0;
		m-=sum;
		printf("%d ",i-2*m+i-1);
		for(int j=i+1;j<=n;j++)
			printf("%d ",int(1e9-2*n*(n-j)));
		puts("");
	}
	return 0;
}