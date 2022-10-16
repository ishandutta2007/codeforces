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
int n,xxj[22],a[xx];
bool in(int x)
{
	int cr=0;
	for(int i=20;i>=0;i--)
	{
		if(x>>i&1)
		{
			if(xxj[i])x^=xxj[i];
			else swap(xxj[i],x),cr=1;
		}
	}
	return cr;
}
bool check(int lim)
{
	memset(xxj,0,sizeof(xxj));
	for(int i=1;i<=n;i++)
		if(a[i]<((1<<lim)))in(a[i]);
	int cr=1;
	for(int i=0;i<lim;i++)
		if(!xxj[i])cr=0;
	return cr;
}
//bitset<32>use[21],lin;
//void rin(int x)
//{
//	for(int i=20;i>=0;i--)
//	{
//		if(x>>i&1)
//		{
//			if(xxj[i])x^=xxj[i],lin^=use[i];
//			else use[i]=lin,swap(xxj[i],x);
//		}
//	}
//}
int id[xx],glm[(int)2e6];
void pre()
{
	for(int i=0;i<20;i++)
		for(int j=(1<<i)+1;j<=(1<<i)*2;j++)
			glm[j]=(1<<i)+glm[(1<<i)*2-j+1];
}
int lg[(int)2e6];
void re(int lim)
{
	memset(xxj,0,sizeof(xxj));
	int tt=0;
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(a[i]<((1<<lim)))if(in(a[i]))id[i]=++tt,v.push_back(a[i]);
	
//	memset(xxj,0,sizeof(xxj));
//	for(int i=1;i<=n;i++)
//	{
//		if(!id[i])continue;
//		lin.reset(),lin[id[i]]=1;
//		rin(a[i]);
//	}
	// 
	///fn... 
	int now=0;
//	cout<<v.size()<<"!!\n";
	for(int i=1;i<=(1<<lim);i++)
	{
		cout<<now<<" ";
//		cout<<glm[i]<<" "<<glm[i+1]<<"\n";
		if(i!=(1<<lim))
		{
			int id=lg[glm[i+1]^glm[i]];
			now^=v[id];
		}
	}
	
}
int main(){
	pre();
	lg[0]=-1;
	for(int i=1;i<=1.5e6;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
//	cout<<check(2)<<"!!\n";
//	exit(0);
	for(int i=0;i<=20;i++)
		if(check(i))ans=i;
	if(ans==0)
	{
		cout<<ans<<"\n";
		cout<<ans<<"\n";
		exit(0);
	}
	cout<<ans<<"\n";
//	cout<<
	re(ans);
//	<<"\n";
	pc('1',1);
	return 0;
}