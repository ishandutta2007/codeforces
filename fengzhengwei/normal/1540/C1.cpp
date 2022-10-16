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
const int xx=105;
int n,c[xx],b[xx];
ll f[xx][xx*xx],S[xx],sum[xx*xx];
const int mod=1e9+7;
ll get(ll x)
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int j=0;j<=10000;j++)sum[j]=f[0][j];
	for(int j=1;j<=10000;j++)sum[j]+=sum[j-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=10000;j++)
		{
//			if(i>90)cout<<S[i]<<"\n";
			if(j<i*x+S[i])continue;
//			for(int k=0;k<=c[i];k++)f[i][j]+=f[i-1][j-k];
			//max(0,j-c[i])~j 
			int l=max(0,j-c[i]),r=j;
			if(l==0)f[i][j]=sum[r];
			else 
			{
//				assert(l);
				f[i][j]=(sum[r]-sum[l-1]+mod)%mod;
			}
//			if(i>90)cout<<i<<" "<<j<<" "<<<<"!!\n";
//			if(f[i][j])cout<<f[i][j]<<"  !!\n";
		}
		for(int j=0;j<=10000;j++)sum[j]=f[i][j];
		for(int j=1;j<=10000;j++)sum[j]+=sum[j-1],sum[j]%=mod;
	}
	return sum[10000];
}
map<int,ll>mp;
int main(){
	
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<n;i++)b[i]=read();
//	n=100;
//	for(int i=1;i<=n;i++)c[i]=100;
//	for(int i=1;i<n;i++)b[i]=100;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)S[i]+=(i-j)*b[j];
//	for(int i=1;i<=n;i++)cout<<S[i]<<"\n";
//	cout<<S[n]<<"!!\n";
	ll s1=1;
	for(int i=1;i<=n;i++)s1*=(c[i]+1),s1%=mod;
	int q=read();
	ll lmin=1e9,rmin=1e9;
	for(int i=1;i<=n;i++)
		lmin=min(lmin,(-S[i])/i);
	for(int i=1;i<=n;i++)
		rmin=min(rmin,(-S[i]+i*100)/i);
	while(q--)
	{
		int x=read();
		if(x<lmin-2)cout<<s1<<"\n";
		else if(x>rmin+2)cout<<0<<"\n";
		else 
		{
			if(mp.find(x)!=mp.end())cout<<mp[x]<<"\n";
			else cout<<(mp[x]=get(x))<<"\n";
		}
	}
	pc('1',1);
	return 0;
}