#include<bits/stdc++.h>
using namespace std;
const int maxn=2010,maxm=4e6+10,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int d[maxn][maxn],f[maxn][maxn],qx[maxm],qy[maxm],h,e;
char s[maxn][maxn];
void pop() {
	h++;
	if(h==maxm)h=0;
}
void hp(int x,int y) {
	if(!h)h=maxm;
	h--;
	qx[h]=x,qy[h]=y;
}
void ep(int x,int y) {
	qx[e]=x,qy[e]=y;
	e++;
	if(e==maxm)e=0;
}
int main() {
	int n,m,r,c,x,y,cnt=0;
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	qx[h=1]=r,qy[1]=c;
	e=2;
	memset(d,0x3f,sizeof(d));
	d[r][c]=0;
	while(h!=e) {
		int x=qx[h],y=qy[h];
		pop();
		if(f[x][y])continue;
		f[x][y]=1;
		for(int i=0;i<4;i++) {
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m)continue;
			if(s[xx][yy]=='*')continue;
			int w=i==2;
			if(d[x][y]+w<d[xx][yy]) {
				d[xx][yy]=d[x][y]+w;
				if(w==0)hp(xx,yy);
				else ep(xx,yy);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			int l=d[i][j]-j+c,r=d[i][j];
			if(l<=x&&r<=y)cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}