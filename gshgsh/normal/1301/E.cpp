#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 601
int N,M,Q,a[MAXN][MAXN],b[MAXN][MAXN][4],c[MAXN][MAXN],st[MAXN][MAXN][10][10];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c;cin>>c;return c=='R'?0:c=='G'?1:c=='Y'?2:3;}void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int ask(int x1,int y1,int x2,int y2){int k1=log2(x2-x1+1),k2=log2(y2-y1+1);return max(max(st[x1][y1][k1][k2],st[x1][y2-(1<<k2)+1][k1][k2]),max(st[x2-(1<<k1)+1][y1][k1][k2],st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]));}
int main()
{
	cin>>N>>M>>Q;For(i,1,N)For(j,1,M)a[i][j]=getc();
	For(i,1,N)For(j,1,M)b[i][j][0]=a[i][j]==0?min(b[i-1][j-1][0],min(b[i-1][j][0],b[i][j-1][0]))+1:0;
	For(i,1,N)FOR(j,M,1)b[i][j][1]=a[i][j]==1?min(b[i-1][j+1][1],min(b[i-1][j][1],b[i][j+1][1]))+1:0;
	FOR(i,N,1)For(j,1,M)b[i][j][2]=a[i][j]==2?min(b[i+1][j-1][2],min(b[i+1][j][2],b[i][j-1][2]))+1:0;
	FOR(i,N,1)FOR(j,M,1)b[i][j][3]=a[i][j]==3?min(b[i+1][j+1][3],min(b[i+1][j][3],b[i][j+1][3]))+1:0;
	For(i,1,N-1)For(j,1,M-1)st[i][j][0][0]=min(min(b[i][j][0],b[i][j+1][1]),min(b[i+1][j][2],b[i+1][j+1][3]));
	for(int k=1;(1<<k)<N;k++)For(i,1,N-(1<<k))For(j,1,M-1)st[i][j][k][0]=max(st[i][j][k-1][0],st[i+(1<<k-1)][j][k-1][0]);for(int k=1;(1<<k)<M;k++)For(i,1,N-1)For(j,1,M-(1<<k))st[i][j][0][k]=max(st[i][j][0][k-1],st[i][j+(1<<k-1)][0][k-1]);
	for(int k1=1;(1<<k1)<N;k1++)for(int k2=1;(1<<k2)<M;k2++)For(i,1,N-(1<<k1))For(j,1,M-(1<<k2))st[i][j][k1][k2]=max(max(st[i][j][k1-1][k2-1],st[i+(1<<k1-1)][j][k1-1][k2-1]),max(st[i][j+(1<<k2-1)][k1-1][k2-1],st[i+(1<<k1-1)][j+(1<<k2-1)][k1-1][k2-1]));
	For(i,1,Q){int x1=get(),y1=get(),x2=get(),y2=get(),l=1,r=min(y2-y1+1,x2-x1+1)>>1,ans=0;while(l<=r){int mid=l+r>>1;ask(x1+mid-1,y1+mid-1,x2-mid,y2-mid)>=mid?ans=mid,l=mid+1:r=mid-1;}put(4*ans*ans),putchar('\n');}return 0;
}