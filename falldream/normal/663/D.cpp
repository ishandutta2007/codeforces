#include<algorithm>
#include<iostream>
#include<cstdio>
#define Rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MN 5000
#define MX 90
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[2][MX+5][MX+5][MX+5],p[MN+5],P[MN+5][4],rk[MN+5],ans=1e9;
int n,ac[MN+5],AC[MN+5],bad=0,s[MN+5][5],q[MN+5],top;
inline int Get(int x)
{
	if(n<2*x&&2*x<=2*n) return 500;
	if(n<4*x&&4*x<=2*n) return 1000;
	if(n<8*x&&8*x<=2*n) return 1500;
	if(n<16*x&&16*x<=2*n) return 2000;
	if(n<32*x&&32*x<=2*n) return 2500;
	if(32*x<=n) return 3000;	
}
inline int Abs(int x){return x<0?-x:x;} 
bool cmp(int x,int y){return p[x]==p[y]?x<y:p[x]>p[y];}
inline void R(int&x,int y){y>x?x=y:0;}
void Solve(int num1,int num2,int num3)
{
	int p1=Get(num1),p2=Get(num2),p3=Get(num3);
	Rep(i,1,n)
	{
		p[i]=0;rk[i]=i;
		if(s[i][1]) p[i]+=(P[i][1]=p1*(250-Abs(s[i][1])));
		if(s[i][2]) p[i]+=(P[i][2]=p2*(250-Abs(s[i][2])));
		if(s[i][3]) p[i]+=(P[i][3]=p3*(250-Abs(s[i][3])));
	}	
	p[1]+=100*250*(ac[1]+ac[2]+ac[3]-num1-num2-num3);
	int mypoint=p[1],rank=1;sort(rk+1,rk+n+1,cmp);top=0;
	Rep(i,1,n) if(p[rk[i]]>mypoint)
	{
		if(s[rk[i]][1]<0||s[rk[i]][2]<0||s[rk[i]][3]<0) q[++top]=rk[i];
		++rank;
	}
	else break;
	int hc1=ac[1]-num1,hc2=ac[2]-num2,hc3=ac[3]-num3;
	Rep(i,0,1) Rep(j,0,hc1) Rep(k,0,hc2) Rep(l,0,hc3) f[i][j][k][l]=-1e9;
	f[0][hc1][hc2][hc3]=0;
	Rep(i,1,top) 
	{
		Rep(j,0,hc1) Rep(k,0,hc2) Rep(l,0,hc3) if(f[~i&1][j][k][l]>=0)
			Rep(h1,0,(s[q[i]][1]<0&&j)) Rep(h2,0,(s[q[i]][2]<0&&k)) Rep(h3,0,(s[q[i]][3]<0&&l))
			{
				int pt=0;
				if(s[q[i]][1]&&!h1) pt+=P[q[i]][1];
				if(s[q[i]][2]&&!h2) pt+=P[q[i]][2];
				if(s[q[i]][3]&&!h3) pt+=P[q[i]][3];
				R(f[i&1][j-h1][k-h2][l-h3],f[~i&1][j][k][l]+(pt<=mypoint));
			}
		Rep(j,0,hc1) Rep(k,0,hc2) Rep(l,0,hc3) f[~i&1][j][k][l]=-1e9;
	}
	int mxhack=0;
	Rep(j,0,hc1) Rep(k,0,hc2) Rep(l,0,hc3) mxhack=max(mxhack,f[top&1][j][k][l]);
	ans=min(ans,rank-mxhack);
}

int main()
{	
	n=read();		
	Rep(i,1,n) Rep(j,1,3)
	{
		s[i][j]=read();
		if(s[i][j]) ++ac[j];
		if(s[i][j]>0) ++AC[j];
		if(s[i][j]<0) ++bad;
	}
	if(bad>=90) return 0*puts("1");
	Rep(i,AC[1],ac[1]) if(i==AC[1]||Get(i)!=Get(i-1))
		Rep(j,AC[2],ac[2]) if(j==AC[2]||Get(j)!=Get(j-1))
			Rep(k,AC[3],ac[3]) if(k==AC[3]||Get(k)!=Get(k-1))
				Solve(i,j,k);
	printf("%d\n",ans);
	return 0;
}