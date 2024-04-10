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
int A,B;
signed main(){
	A=read(),B=read();
	int len=A+B,ans=0;
	for(int l=1,r;l<=len;l=r+1)
	{
		r=len/(len/l);
		int w=len/l;
		//rangel~r 
		int ral=(A+w)/(w+1),rar=(A/w);
		int rbl=(B+w)/(w+1),rbr=(B/w);
		if(ral>rar)continue;
		if(rbl>rbr)continue;
		int tl=ral+rbl,tr=rar+rbr;
		ans+=max(0,min(tr,r)-max(tl,l)+1);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}