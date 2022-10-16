#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=2005;
int n,f[2][xx],a[xx],b[xx],t[xx];
void ad(int &a,int b){if(a>b)a=b;}
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			char c;
			while((c=getchar())>'z'||c<'a');
			a[i]=c-'a'+1;
		}
		for(int i=1;i<=n;i++)
		{
			char c;
			while((c=getchar())>'z'||c<'a');
			b[i]=c-'a'+1;
		}
		for(int i=1;i<=26;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[a[i]]++;
		int vs=1;
		for(int i=1;i<=n;i++)
		{
			t[b[i]]--;
			if(t[b[i]]<0)
			{
				puts("-1");vs=0;
				break;
			}
		}
//		puts("QWewqeq");
		if(!vs)continue;
		memset(f,0x3f,sizeof(f));
		b[0]=-1;
		f[(n+1)&1][n]=0;
		for(int i=n+1;i>=1;i--)
		{
			for(int j=n;j>=i;j--)t[a[j]]++;
			for(int j=n;j>=0;j--)
			{
				ad(f[(i&1)^1][j],f[i&1][j]+1);
				if(j&&t[b[j]])ad(f[i&1][j-1],f[i&1][j]);
				if(a[i-1]==b[j])ad(f[(i&1)^1][j-1],f[i&1][j]);
				if(!j)break;
				t[b[j]]--;
				if(t[b[j]]<0)break;
			}
			if(i==1)
			{
				cout<<f[i&1][0]<<"\n";
				break;
			}
			for(int j=n;j>=0;j--)f[i&1][j]=1e9;
			for(int j=26;j>=0;j--)t[j]=0;
		}
	}
	pc('1',1);
	return 0;
}