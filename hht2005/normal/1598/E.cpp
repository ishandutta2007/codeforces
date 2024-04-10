#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],n,m;
int calc(int X) {
	if(X<=1-m)return 0;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++) {
		int j=i-X;
		if(1<=j&&j<=m) {
			if(a[i][j])ans+=sum++;
			else sum=0;
		}
		j++;
		if(j<1||j>m)continue;
		if(a[i][j])ans+=sum++;
		else sum=0;
	}
	return ans;
}
int main() {
	int q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	int ans=n*m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=1;
	for(int i=2-m;i<=n-1;i++)
		ans+=calc(i);
	while(q--) {
		scanf("%d%d",&x,&y);
		ans-=a[x][y];
		ans-=calc(x-y);
		ans-=calc(x-y+1);
		a[x][y]^=1;
		ans+=a[x][y];
		ans+=calc(x-y);
		ans+=calc(x-y+1);
		printf("%d\n",ans);
	}
	return 0;
}