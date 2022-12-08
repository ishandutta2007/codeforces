#include<bits/stdc++.h>
using namespace std;
char s[210][210];
int cnt,x[5],y[5];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		char a=s[1][2],b=s[2][1],c=s[n-1][n],d=s[n][n-1];
		cnt=0;
		if(a==b) {
			if(c==a)x[++cnt]=n-1,y[cnt]=n;
			if(d==a)x[++cnt]=n,y[cnt]=n-1;
		} else if(c==d) {
			if(a==c)x[++cnt]=1,y[cnt]=2;
			if(b==c)x[++cnt]=2,y[cnt]=1;
		} else {
			if(b!=a)x[++cnt]=2,y[cnt]=1;
			if(c==a)x[++cnt]=n-1,y[cnt]=n;
			if(d==a)x[++cnt]=n,y[cnt]=n-1;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
			printf("%d %d\n",x[i],y[i]);
	}
}