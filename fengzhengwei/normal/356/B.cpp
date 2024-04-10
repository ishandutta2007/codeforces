#include<bits/stdc++.h>
#define ll long long
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
const int xx=1e6+5;
ll a,b,vis[xx],n,m,t[27];
char s[xx],c[xx];
int main(){
	a=read(),b=read();
	scanf("%s",s);
	scanf("%s",c);
	n=strlen(s);
	m=strlen(c);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			memset(t,0,sizeof(t));
			int x=(i+n)%m;
			ll re=0;
			while(x!=i)
			{
				t[c[x]-'a']++,re++;
				x+=n,x%=m;
			}
			vis[x]=1;
			t[c[x]-'a']++,re++;
			x=(i+m)%n;
			while(x!=i)
			{
				vis[x]=1;
				ans+=(re-t[s[x]-'a'])*(a/re);
				x+=m,x%=n;
			}
			vis[x]=1;
			ans+=(re-t[s[x]-'a'])*(a/re);
		}
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}