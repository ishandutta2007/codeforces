#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
char s[xx];
const int mod=998244353;
ll jiec[xx];
ll ni[xx];
ll C(ll n,ll m)
{
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	int n=read(),k=read();
	if(k==0)
	{
		puts("1");
		exit(0);
	}
	scanf("%s",s+1);
	int tt=0;
	for(int i=1;i<=n;i++)if(s[i]=='1')tt++;
	if(k>tt)
	{
		puts("1");
		exit(0);
	}
	int res=0,id=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')res++;
		if(res==k)id=i;
	}
	ll ans=0;
	ans+=C(id,k);
//	cout<<id<<" "<<k<<"QWEW\n";
	int num0=id-k,num1=k,l=1;
	// 
	for(int i=id+1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			while(s[l]!='1')
			{
				num0--;
				l++;
			}
			num1--;
			l++;
			num1++;
		}
		else 
		{
			num0++;
		}
		if(s[i]=='1')
		{
			if(!num0)continue;
			ans+=C(num0+num1-1,num0-1);
		}
		else 
		{
			if(!num1)continue;
			ans+=C(num0+num1-1,num1-1);
		}
		// 
	}
	cout<<ans%mod<<"\n";
	
	
	
	
	
	pc('1',1);
	return 0;
}