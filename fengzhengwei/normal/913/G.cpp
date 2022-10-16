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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
#define __ __int128
void wt(__ x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(__ x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
ll a;
__ ksm(__ a,__ b,__ mod)
{
	__ ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int main(){
	int T=read();
	while(T--)
	{
		a=read();
		int n=0;
		{
			ll x=a;
			while(x)x/=10,n++;
		}
		//  
		//n+m 
		//n<=11
		//m=6 
		//m=10int128 
		int m=6;
		//10^m>2^{n+m}
		__ mod=1ll<<n+m;//<=1e6
		//b0~10^m 
		ll t1=a%mod*ksm(10,m,mod)%mod,t2=mod-t1;
		if(t2%5==0)t2+=mod;//gcd=1 
		__ x;
		x=a*ksm(10,m,1e32)+t2;
//		cout<<t1<<" "<<t2<<"ASDASd\n";
		x/=mod;
		int t=n+m;
		// 
		__ num=25;
		__ fi=4;
		__ ans=0;
		for(int i=0;i<4;i++)if(ksm(2,i,5)==x%5)ans=i;
//		wts(x,'\n');
		//fifi 
		for(int i=2;i<=t;i++)
		{
			// 
			for(int j=0;j<5;j++)// 
			{
				if(ksm(2,ans+fi*j,num)==x%num)
				{
//					wts(x%num,'\n');
//					wts(ksm(2,ans+fi*j,num),'\n');
//					pc('1',1);
//					puts("Cr");
					ans+=j*fi;
					break;
				}
			}
//		wts(i,' ');
//		wts(fi,'\n');
//		wts(num,'\n');
//		wts(ans,'\n');
//		wts(ksm(2,ans+7,10000000),'\n');
//		pc('1',1);
			num*=5,fi*=5;
		}
		// 
		wts(ans+t,'\n');
		pc('1',1);
	}
	pc('1',1);
	return 0;
}