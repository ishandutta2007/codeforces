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
const int xx=1e6+5;
int n,col[xx],dlt,tt,C;
//+ 
void mk(int x)
{
	if(x*2<=tt)
	{
		col[x*2]=col[x]^1;
		col[x*2+1]=col[x];
		mk(x*2),mk(x*2+1);
	}
}
void bin(int x)
{
	if(x*2<=tt)bin(x*2);
	//=C 
	++dlt;
//	cout<<x<<" "<<col[x]<<" "<<C<<" "<<dlt<<"!\n";
	if(col[x]==C)
	{
		if(!(dlt&1))++dlt;// 
	}
	else 
	{
		if(dlt&1)++dlt;
	}
	if(x*2<=tt)bin(x*2+1);
}
int main(){
	//1 
	n=read();
	//1/2 
	if(n==1)
	{
		puts("1");
		return 0;
	}
	if(n==2)
	{
		puts("1");
		return 0;
	}
	if(n==3)
	{
		puts("0");
		return 0;
	}
	//4/5 
	//40/41 
	int num=1;//k2^k-1 
	while((1<<(num+1))-1<=n)num++;
	dlt=0;
	tt=(1<<num)-1;
//	cout<<num<<"!!!\n"<<" "<<(1<<num-1)<<" "
	mk(1);
	C=col[(1<<num-1)];
//	cout<<C<<"!!!\n";
	bin(1);
	if(n==dlt||n==dlt+1)puts("1");
	else puts("0");
//	cout<<dlt<<"\n";
	
	pc('1',1);
	return 0;
}