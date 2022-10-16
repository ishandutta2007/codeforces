#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
int T;
const int xx=2005;
char s[xx],c[xx];
char to[xx];
int f[xx][xx<<1];
int g[xx][xx<<1];
bool ck(int id,int i,char *w)
{
	if(w[i]=='?'||w[i]-'0'==id)return 1;
	return 0;
}
const int mod=1e9+7;
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int main(){
	to['1']='0';
	to['0']='1';
	to['?']='?';
	T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		scanf("%s",c+1);
		for(int i=1;i<=n;i++)
			if(i&1)s[i]=to[s[i]];
		for(int i=1;i<=n;i++)
			if(i&1)c[i]=to[c[i]];
		for(int i=0;i<=n;i++)
			for(int j=-n;j<=n;j++)
				f[i][j+xx]=g[i][j+xx]=0;
		f[0][xx]=1;
		for(int i=0;i<=n;i++)
		{
			for(int j=-n;j<=n;j++)
			{
				if(!f[i][j+xx])continue;
//				cout<<i<<" "<<j<<" "<<f[i][j+xx]<<" "<<g[i][j+xx]<<"QWE\n";
				for(int a=0;a<=1;a++)
				{
					if(!ck(a,i+1,s))continue;
					for(int b=0;b<=1;b++)
					{
						if(!ck(b,i+1,c))continue;
						ad(f[i+1][j+a-b+xx],f[i][j+xx]);
						ad(g[i+1][j+a-b+xx],(g[i][j+xx]+1ll*abs(j+a-b)*f[i][j+xx])%mod);
					}
				}
			}
		}
		cout<<g[n][xx]<<"\n";
	}
	pc('1',1);
	return 0;
}