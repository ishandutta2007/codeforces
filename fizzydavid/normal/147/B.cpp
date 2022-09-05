//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
#define output1(x) putnum(x)
#define output2(x,y) output1(x),putnum(y)
#define output3(x,y,z) output2(x,y),putnum(z)
#define output4(x,y,z,w) output3(x,y,z),putnum(w)
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
int n,m;
struct matrix
{
	int a[311][311];
	void init()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=(i==j)?0:-INF;
	}
	matrix operator*(const matrix &tmp)
	{
		matrix res;res.init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					res.a[i][j]=max(res.a[i][j],a[i][k]+tmp.a[k][j]);
		return res;
	}
}f[10],M;
bool check(const matrix &tmp)
{
	for(int i=1;i<=n;i++)
		if(tmp.a[i][i]>0)
			return true;
	return false;
}
int main()
{
	input2(n,m);
	int x,y,c1,c2;f[0].init();
	for(int i=1;i<=m;i++)
	{
		input4(x,y,c1,c2);
		f[0].a[x][y]=c1;
		f[0].a[y][x]=c2;
	}
	for(int i=1;(1<<i)<=n;i++)
		f[i]=f[i-1]*f[i-1];
	int ans=0;M.init();
	for(int i=9;i>=0;i--)
	{
		if((1<<i)>n)continue;
		matrix tmp=M*f[i];
		if(!check(tmp))
			M=tmp,ans+=1<<i;
	}
	M=M*f[0];
	if(check(M))
		putnum(ans+1),putendl();
	else
		puts("0");
	return 0;
}
/*
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 -1
3 4 0 -3

*/