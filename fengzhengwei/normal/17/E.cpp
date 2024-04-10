#include<bits/stdc++.h>
#define ll long long
//#define int ll
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
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
	wt(x),pc(op,0);
}
const int xx=2e6+5;
struct no{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int& To(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to==y)return e[i].id;
	add(x,y,0);
	return e[cnt].id;
}
struct nod{int fail,size,dp;}E[xx];
char s[xx];
int lst,cst;
void add(int x,int id)
{
	int p=lst;
//	cerr<<p<<" "<<id<<" "<<E[p].size<<"\n";
	while(s[id]!=s[id-E[p].size-1])p=E[p].fail;
	int &T=To(p,x);
	if(!T)T=++cst; 
	E[T].size=E[p].size+2;
	//fail 
	if(E[T].size==1)E[T].fail=2;
	else 
	{
//		cerr<<p<<" "<<E[T].size<<" "<<<<"ASD\n";
		p=E[p].fail;
		while(s[id]!=s[id-E[p].size-1])p=E[p].fail;
//	,cerr<<p<<"!!\n";;
		E[T].fail=To(p,x);
	}
	lst=T;
	E[lst].dp=E[E[lst].fail].dp+1;
}
ll num[xx],sum[xx];
const int mod=51123987;
signed main(){
	++cst;E[cst].fail=0,E[cst].size=-1;//1 
	++cst;E[cst].fail=1,E[cst].size=0;
	lst=1;
//	cout<<sizeof(e)/1024/1024<<"\n";
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)add(s[i]-'a',i),num[i]=E[lst].dp;
//	,cerr<<i<<" "<<num[i]<<"!!\n";
	memset(h,0,sizeof(h)),cnt=0;
	memset(E,0,sizeof(E)),cst=0;
	++cst;E[cst].fail=0,E[cst].size=-1;//1 
	++cst;E[cst].fail=1,E[cst].size=0;
	lst=1;
	reverse(s+1,s+n+1);
	for(int i=1;i<=n;i++)add(s[i]-'a',i),sum[i]=sum[i-1]+E[lst].dp,sum[i]%=mod;
//	,cerr<<E[lst].dp<<"!!\n";
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=num[i]*sum[n-i],ans%=mod;
//	cerr<<ans<<"!!\n";
	cout<<(((sum[n]*(sum[n]-1)/2)%mod-ans)%mod+mod)%mod<<"\n";
	pc('1',1);
	return 0;
}