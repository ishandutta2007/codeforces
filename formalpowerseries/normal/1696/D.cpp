#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int MOD=998244353;
inline int Add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
inline int Sub(int x,int y){return x<y?x-y+MOD:x-y;}
inline int Mul(int x,int y){return 1ll*x*y%MOD;}
int QuickPow(int x,int p)
{
	int ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
int n;
int a[250005];
int minn[20][250005],maxn[20][250005];
int ag1[20][250005],ag2[20][250005];
int lgs[250005];
int queryMax(int l,int r)
{
	int d=lgs[r-l+1];
	return max(maxn[d][l],maxn[d][r-(1<<d)+1]);
}
int queryMin(int l,int r)
{
	int d=lgs[r-l+1];
	return min(minn[d][l],minn[d][r-(1<<d)+1]);
}
int queryMaxA(int l,int r)
{
	int d=lgs[r-l+1];
	if(maxn[d][l]>maxn[d][r-(1<<d)+1])	return ag2[d][l];
	else	return ag2[d][r-(1<<d)+1];
}
int queryMinA(int l,int r)
{
	int d=lgs[r-l+1];
	if(minn[d][l]<minn[d][r-(1<<d)+1])	return ag1[d][l];
	else	return ag1[d][r-(1<<d)+1];
}
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=1;i<=n;++i)	minn[0][i]=maxn[0][i]=a[i],ag1[0][i]=ag2[0][i]=i;
	for(int i=1;i<=19;++i)
	{
	for(int j=1;j+(1<<i)-1<=n;++j)
	{
		minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
		maxn[i][j]=max(maxn[i-1][j],maxn[i-1][j+(1<<(i-1))]);
		if(minn[i][j]==minn[i-1][j])	ag1[i][j]=ag1[i-1][j];
		else	ag1[i][j]=ag1[i-1][j+(1<<(i-1))];
		if(maxn[i][j]==maxn[i-1][j])	ag2[i][j]=ag2[i-1][j];
		else	ag2[i][j]=ag2[i-1][j+(1<<(i-1))];
	}
	}
	int p=1,ans=0;
	while(p^n)
	{
		if(a[p]<a[p+1])
		{
			int l=p+1,r=n,P=p+1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(queryMin(p,mid)==a[p])	l=mid+1,P=mid;
				else	r=mid-1;
			}
			p=queryMaxA(p+1,P);
		}
		else
		{
			int l=p+1,r=n,P=p+1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(queryMax(p,mid)==a[p])	l=mid+1,P=mid;
				else	r=mid-1;
			}
			p=queryMinA(p+1,P);
		}
		++ans;
	}
	write(ans),puts("");
}
int main(){
	for(int i=2;i<=250000;++i)	lgs[i]=lgs[i>>1]+1;
	int T=read();
	while(T-->0)Solve();
	return 0;
}