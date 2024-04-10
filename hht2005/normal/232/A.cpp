#include<bits/stdc++.h>
using namespace std;
int s[110][110],pre[100010];
int main() {
	int m,T=0;
	scanf("%d",&m);
	for(int i=3;i<=100;i++)
		if(i*(i-1)*(i-2)/6<=m)
			T=i;
	for(int i=1;i<=T;i++)
		for(int j=1;j<=T;j++)
			if(i!=j)s[i][j]=1;
	m-=T*(T-1)*(T-2)/6;
	memset(pre,-1,sizeof(pre));
	pre[0]=0;
	for(int i=2;i<=100;i++) {
		int a=i*(i-1)/2;
		for(int j=a;j<=m;j++)
			if(~pre[j-a])pre[j]=i;
	}
	int cnt=T;
	while(m) {
		for(int i=1;i<=pre[m];i++)
			s[i][cnt+1]=s[cnt+1][i]=1;
		int t=pre[m]*(pre[m]-1)/2;
		cnt++;
		m-=t;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) {
		for(int j=1;j<=cnt;j++)
			putchar(s[i][j]+'0');
		puts("");
	}
	return 0;
}