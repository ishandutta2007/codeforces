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
const int xx=1e5+5;
int f[105][10005];//fijij1 
int fr[105][10005];
int G(int a){return a*(a-1)/2;}
int gt(int n,int b)
{
	if(b<0)return 0;
	if(f[n][b]!=-1)return f[n][b];
	f[n][b]=0;
	for(int i=4;i<=n;i++)
	{
		f[n][b]|=gt(n-(i-1),b-1);
		if(gt(n-(i-1),b-1))fr[n][b]=i;
	}
	// 
	for(int i=2;i<=n;i++)
	{
		f[n][b]|=gt(n-(i-1),b-G(i));
		if(gt(n-(i-1),b-G(i)))fr[n][b]=n+i;
	}
	// 
	return f[n][b];
}
int cr[xx];//012 
vector<int>to[xx];
int tt;
struct mydeq
{
	int q[xx+xx],l,r;
	void cls(){l=xx,r=l-1;}
	int size(){return r-l+1;}
	int eL(){return q[l++];}
	int eR(){return q[r--];}
	void inL(int x){q[--l]=x;}
	void inR(int x){q[++r]=x;}
	int L(){return q[l];}
	int R(){return q[r];}
}q;
void out(int x)
{
	if(!to[x].size())return cout<<x<<" ",void();
	if(!cr[x])
	{
		// 
		int l=2,r=to[x].size(),vs=0;// 
		while(l<r)
		{
			if(!vs)out(to[x][(l++)-1]);
			else out(to[x][(r--)-1]);
			vs^=1;
		}
		out(to[x][0]),out(to[x][l-1]);
	}
	else 
	{
//		if(cr[x]==2)assert(0);
//		cout<<x<<" "<<cr[x]<<"\n";
		if(cr[x]==2)reverse(to[x].begin(),to[x].end());
		// reverse 
		for(int i=0;i<to[x].size();i++)
		{
			if(cr[to[x][i]])cr[to[x][i]]=3-cr[x];
//			^(2-cr[x]);
			out(to[x][i]);
		}
	}
}
void build(int n,int b)
{
	if(n==1&&b==0)return out(q.L());
//		cout<<n<<" "<<b<<" "<<fr[n][b]<<" "<<f[n][b]<<"!\n";
	if(fr[n][b]<=n)
	{
		tt++,cr[tt]=0;
		int a=fr[n][b];
		while(a--)to[tt].push_back(q.eL());
//		cout<<"!!!\n";
		q.inL(tt);
		build(n-(fr[n][b]-1),b-1);
	}
	else 
	{
		tt++,cr[tt]=1;
		int a=fr[n][b]-n;
		while(a--)to[tt].push_back(q.eL());
		q.inL(tt);
		build(n-(fr[n][b]-n-1),b-G(fr[n][b]-n));
	}
}
int main(){
//	cout<<gt(5,3)<<"\n";
	memset(f,-1,sizeof(f));
	f[1][0]=1;
	int qq=read();
	while(qq--)
	{
		int a=read(),b=read();
		if(gt(a,b-a))
		{
			puts("YES");
			for(int i=1;i<=a+a;i++)to[i].clear(),cr[i]=0;
			tt=a;q.cls();
			for(int i=1;i<=tt;i++)q.inR(i);
			build(a,b-a);
			puts("");
		}
		else puts("NO");
	}
//	for(int i=4;i<=100;i++)f[i][1]=1;
	pc('1',1);
	return 0;
}