#include<bits/stdc++.h>
using namespace std;
#define y1 sdgl
const int maxn=110,maxm=30010;
int a[maxn][maxn],X[maxm][4],Y[maxm][4],cnt,n,m;
char s[maxn][maxn];
void opt(int xx,int yy,int x,int y) {
	int cc=0;
	cnt++;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			if(xx+i!=x||yy+j!=y) {
				X[cnt][cc]=xx+i;
				Y[cnt][cc++]=yy+j;
				a[xx+i][yy+j]^=1;
			}
}
void calc(int x,int y) {
	int cnt=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cnt+=a[x+i][y+j];
	if(cnt==1) {
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				if(a[x+i][y+j]) {
					for(int a=0;a<2;a++)
						for(int b=0;b<2;b++)
							if(a!=i||b!=j)opt(x,y,x+a,y+b);
					return;
				}
	}
	if(cnt==2) {
		int X[2]={0},Y[2]={0},cc=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				if(a[x+i][y+j])X[cc]=x+i,Y[cc++]=y+j;
		opt(x,y,X[0],Y[0]);
		opt(x,y,X[1],Y[1]);
	}
	if(cnt==3) {
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				if(!a[x+i][y+j]) {
					opt(x,y,x+i,y+j);
					return;
				}
	}
	if(cnt==4) {
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				opt(x,y,x+i,y+j);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				a[i][j]=s[i][j]&1;
		}
		if(n&1) {
			for(int i=1;i<m;i++)
				if(a[1][i])opt(1,i,1,i+1);
			if(a[1][m])opt(1,m-1,1,m-1);
		}
		if(m&1) {
			for(int i=1+n%2;i<n;i++)
				if(a[i][1])opt(i,1,i+1,1);
			if(a[n][1])opt(n-1,1,n-1,1);
		}
		for(int i=1+n%2;i<=n;i+=2)
			for(int j=1+m%2;j<=m;j+=2)
				calc(i,j);
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) {
			for(int j=0;j<3;j++)
				printf("%d %d ",X[i][j],Y[i][j]);
			puts("");
		}
	}
	return 0;
}