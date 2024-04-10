#include<bits/stdc++.h>
using namespace std;
int a[25][25];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0){
		int n,m;
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(!(i==1 || j==1 || i==n || j==m))	continue;
				if(!a[i-1][j-1] && !a[i-1][j] && !a[i-1][j+1] && !a[i][j-1])	a[i][j]=1;
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)	printf("%d",a[i][j]);
			puts("");
		}
	}
	return 0;
}