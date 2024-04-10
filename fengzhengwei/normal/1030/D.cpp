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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
const int xx=505,yy=1e6+5;
int n,m,k;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main(){
	n=read(),m=read(),k=read();
	if(1ll*n*m*2%k)
		puts("NO"),exit(0);
	puts("YES");
	if(k%2==0)
	{
		k/=2;
		int l=n/gcd(n,k);
		k/=gcd(n,k);
		int r=m/gcd(m,k);
		cout<<0<<" "<<0<<"\n";
		cout<<0<<" "<<r<<"\n";
		cout<<l<<" "<<0<<"\n";
		exit(0);
	}
	else 
	{
		int l=n/gcd(n,k);
		k/=gcd(n,k);
		int r=m/gcd(m,k);
		if(l*2<=n)l*=2;
		else r*=2;
		cout<<0<<" "<<0<<"\n";
		cout<<0<<" "<<r<<"\n";
		cout<<l<<" "<<0<<"\n";
		exit(0);
	}
	pc('1',1);
	return 0;
}