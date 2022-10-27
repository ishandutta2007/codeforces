// LUOGU_RID: 90278951
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
//a 
int lim,nw;
vector<int>v1,v2;
bitset<10000002>c1,c2;
// number up /down  /  
void dfs(int x,int ls)
{
	if(x==lim+1)
	{
		v1.push_back(ls);
		if(nw)v2.push_back(ls);
		return c1[ls]=1,c2[ls]=nw,void();
	}
	for(int i=(x==1);i<=9;i++)
	{
		if(ls%10==i)continue;
		if(x<=2||((i>ls%10)^(ls%10>(ls/10)%10)))dfs(x+1,ls*10+i);
	}
}
const int div=1e7;
inline int gls(ll x){return x%10;}
inline int gup(ll x){return (x/1000000)%10;}
inline int gop(ll x){return gls(x)<gls(x/10);}
bool ck(int up,int dw)
{
	int t1=gop(dw),t2,t3,t4;
	
	return ((!up)&&c1[dw])||(c1[up]&&c2[dw]&&(up<10||(t1^(t2=gop(up))))&&(t3=gls(up))!=(t4=gup(dw))&&((t4<t3)==t1));
}
bool cks(int up,int t4,int t1)
{
	assert(up&&c1[up]);
	int t2,t3;
	return (up<10||(t1^(t2=gop(up))))&&(t3=gls(up))!=t4&&((t4<t3)==t1);
}
int t[10][2][(int)1e6+5];
char ED;
int main(){
//	freopen("a.in","r",stdin);
//	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	// 100  
	ll n=read(),k=read();
	for(lim=1;lim<=7;lim++)
	{
		if(lim>=6)nw=1;
		dfs(1,0);
//		cerr<<v.size()<<"#\n";
	}
	c1[0]=1;
	//8e5  
//	cerr<<v1.size()<<" "<<v2.size()<<"$\n";
	if(n>=1e6)
	{
		ll ct=0;
		for(ll ty=n;ty<=1e14;ty+=n)
		{
			int up=ty/div,dw=ty%div;
			if(ck(up,dw))++ct;
			if(ct==k)return cout<<ty<<"\n",0;
		}
		puts("-1");
		return 0;
	}
	else 
	{
		ll ct=0;
		for(auto it:v1)
		{
			if(it%n==0)++ct;
			if(ct==k)return cout<<it<<"\n",0;
		}
//		for(auto it:v2)if(it%n==76966)cerr<<it<<"@@\n"
		for(auto it:v2)
			t[gup(it)][gop(it)][it%n]++;
		for(auto up:v1)
		{
//			cerr<<up<<"#\n"; 
			int rem=n-1ll*div*up%n;
//			cerr<<up<<" "<<rem<<" "<<ct<<"$$\n";
			if(rem==n)rem=0;
			ll tc=ct;
			for(int j=0;j<10;j++)
				for(int w=0;w<=1;w++)
					if(cks(up,j,w))tc+=t[j][w][rem];
			if(tc<k)ct=tc;
			else 
			{
				for(auto dw:v2)
				{
					if(ck(up,dw)&&dw%n==rem)++ct;
					if(ct==k)return cout<<1ll*up*div+dw<<"\n",0;
				}
				assert(0);
				return 0;
			}
		}
//		cerr<<ct<<"#\n";
		puts("-1");
		return 0;
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}