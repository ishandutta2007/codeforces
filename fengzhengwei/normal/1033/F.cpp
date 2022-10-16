#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
int w,n,m,ct[xx],_ct[16777219],cv[xx];//16777216
ll ans;
char s[xx];
int To[xx];
int is[6]={0,1,0,1,0,0};
int zzb[6][4]={0,3,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,3,0,1,0,1,1,0};
void down(int x,int y,int now,int d)
{
//	cout<<now<<" "<<d<<" "<<s[d]<<" "<<To[s[d]]<<"!!\n";
	if(now==-1)
		return /*cerr<<x<<" "<<y<<"!\n",*/ans+=_ct[x]*_ct[y],void();
	if(is[To[s[d]]])return down(x+(zzb[To[s[d]]][0]<<(now+now)),y+(zzb[To[s[d]]][1]<<(now+now)),now-1,d+1);
	down(x+(zzb[To[s[d]]][0]<<(now+now)),y+(zzb[To[s[d]]][1]<<(now+now)),now-1,d+1);
//	cout<<zzb[To[s[d]]][2]<<" "<<zzb[To[s[d]]][3]<<" "<<s[d]<<" "<<d<<"!!!\n";
	down(x+(zzb[To[s[d]]][2]<<(now+now)),y+(zzb[To[s[d]]][3]<<(now+now)),now-1,d+1);
}
int main(){
	To['A']=0,To['O']=1,To['X']=2,To['a']=3,To['o']=4,To['x']=5;
	w=read(),n=read(),m=read();
	for(int i=1;i<=n;i++)ct[read()]++;
	for(int i=0;i<(1<<w);i++)
	{
		for(int j=0;j<w;j++)
		if(i>>j&1)cv[i]+=(1<<(j+j))+(1<<(j+j+1)); 
	}
	for(int i=0;i<(1<<w);i++)
	{
		int to=0;
		for(int j=0;j<w;j++)
			if(i>>j&1)to+=(1<<(j+j));
		for(int j=0;j<(1<<w);j++)
			_ct[cv[j]|to]+=ct[i];
//			,cerr<<(cv[j]|to)<<"!!\n";
	}
//	for(int i=0;i<(1<<w+w);i++)cout<<i<<" "<<_ct[i]<<"!!\n";
	// 
	for(int i=1;i<=m;i++)
	{
		ans=0,scanf("%s",s);
		down(0,0,w-1,0);
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}