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
const int xx=205;
int bits[xx];
char L[25],R[25];
int to[xx];
void dec()
{
	int len=strlen(L);
	for(int i=len-1;i>=0;i--)
	{
		if(L[i]!='0')
		{
			if(L[i]=='a')L[i]='9';
			else L[i]--;
			for(int j=i+1;j<len;j++)L[j]='f';
			break;
		}
	}
	if(len!=1&&L[0]=='0')
	{
		for(int i=1;i<len;i++)L[i-1]=L[i];
		L[len-1]=0;
	}
}
// 
//16 
ll f[17][2][2][2];//0 
int mj,ty,gs;
//0 
ll dfs(int k,int iq,int im,int bit)
{
//	cout<<k<<" "<<iq<<" "<<im<<' '<<bit<<"\n";
	if(k==0)return im;
	if(f[k][iq][im][bit]!=-1)return f[k][iq][im][bit];
	f[k][iq][im][bit]=0;
	int lim=bit?bits[k]:15;
	ll ans=0;
	for(int i=0;i<=min(mj,lim);i++)
	{
		if(k==ty&&(!(i>>gs&1)))continue;
		ans+=dfs(k-1,iq&(i==0),im|(i==mj),bit&(i==lim));
	}
	return f[k][iq][im][bit]=ans;
}
ll solve(char *s)
{
//	cout<<s<<'\n';
	bits[0]=0;
	int len=strlen(s);
	if(len==1&&s[0]=='0')return 0;
	for(int i=len-1;i>=0;i--)bits[++bits[0]]=to[s[i]];
	ll ans=0;
	//0 
	for(int i=1;i<=15;i++)
	{
		memset(f,-1,sizeof(f));
		mj=i,ty=i/4+1,gs=i-(ty-1)*4;
		if(bits[0]>=ty)ans+=dfs(bits[0],1,0,1);
//	cout<<s<<" "<<i<<" "<<ty<<" "<<gs<<' '<<ans<<" "<<dfs(bits[0],1,0,1)<<"\n";
	}
	return ans;
}
signed main(){
	for(int i=0;i<10;i++)to['0'+i]=i;
	for(int i=0;i<6;i++)to['a'+i]=10+i;
	int T=read();
	while(T--)
	{
		scanf("%s",L),scanf("%s",R);
		if(strlen(L)==1&&L[0]=='0')cout<<solve(R)<<"\n";
		else dec(),cout<<solve(R)-solve(L)<<"\n";
	}
	pc('1',1);
	return 0;
}