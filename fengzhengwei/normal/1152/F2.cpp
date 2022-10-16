#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int n,k,m;
const int mod=1e9+7;
struct mat
{
	ll a[209][209];
	mat(){memset(a,0,sizeof(a));}
	mat operator*(const mat&w)const
	{
		mat c;
		for(int i=0;i<209;i++)
		{
			for(int k=0;k<209;k++)
			{
				ll z=a[i][k];
				for(int j=0;j<209;j++)
					c.a[i][j]+=z*w.a[k][j]%mod;
			}
		}
		for(int i=0;i<209;i++)
		for(int j=0;j<209;j++)c.a[i][j]%=mod;
		return c;
	}
}ans,zy;
//int to[];
int A[13][16];
int to(int x,int y){return (&A[x][y])-(&A[0][0]);}
signed main(){
//	cout<<a<<" "<<((&a[2][1])-(&a[0][0]))<<" "<<&a[0][0]<<"\n";
	n=read(),k=read(),m=read();
	ans.a[0][to(0,0)]=1;
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			zy.a[to(i,j)][to(i,(j<<1)&((1<<m)-1))]++;
			if(i!=k)zy.a[to(i,j)][to(i+1,(j<<1|1)&((1<<m)-1))]+=__builtin_popcount(j)+1;
		}
	}
	while(n)
	{
		if(n&1)ans=ans*zy;
		zy=zy*zy,n>>=1;
	}
	ll res=0;
	for(int j=0;j<(1<<m);j++)res+=ans.a[0][to(k,j)];
	res%=mod;
	cout<<res<<"\n";
	pc('1',1);
	return 0;
}