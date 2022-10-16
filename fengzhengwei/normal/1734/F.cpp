#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define ull unsigned ll 
#define LL __int128
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	(op||(((*s++)=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
ll f[65][2][65][2],n,m;
int b1[65],b2[65];
ll dfs(int x,int y,int lst,int bit)
{
//	cerr<<x<<" "<<y<<" "<<lst<<" "<<bit<<"%%\n";
	if(x==0)return y;
	if(f[x][y][lst][bit]!=-1)return f[x][y][lst][bit];
	ll ans=0;
	int k=bit?b1[x]:1;
	for(int i=0;i<=k;i++)
		ans+=dfs(x-1,y^i^(i+b2[x]==1)^((i+b2[x]==2)&((lst+1)&1)),(lst+(i+b2[x]==1))&(i+b2[x]==1),bit&(i==k));
	return f[x][y][lst][bit]=ans;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(f,-1,sizeof(f));
		n=read(),m=read();
		--m;
		for(int i=1;i<=63;i++)b1[i]=(m>>(i-1)&1),b2[i]=(n>>(i-1)&1);
		cout<<dfs(63,0,0,1)<<"\n";
	}
	pc('1',1);
	return 0;
}