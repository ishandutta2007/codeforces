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
//  
const int xx=1e6+5,base=2011111,mod=1e9+7;
int n;
char s[xx];
string a[xx];
vector<ll>sum[xx];
ll pw[xx],ni;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll get(int id,int t,int len)//t 
{
	if(t==-1)return sum[id][len];
	if(len<t)return sum[id][len];
	len++;
	return ((t?sum[id][t-1]:0)+(sum[id][len]-sum[id][t]+mod)*ni)%mod;
}
char G(int id,int t,int len)
{
	if(t==-1)return a[id][len];
	if(len<t)return a[id][len];
	len++;
	return a[id][len];
}
//11<2,01>2,2 
int cmp(int id1,int id2,int t1,int t2,int len1,int len2)
{
	int l=0,r=min(len1-(t1!=-1),len2-(t2!=-1)),ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(get(id1,t1,mid)==get(id2,t2,mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	//ans 
	if(ans==min(len1-(t1!=-1),len2-(t2!=-1)))
	{
		if(len1-(t1!=-1)==len2-(t2!=-1))return 2;
		return len1-(t1!=-1)<len2-(t2!=-1);
	}
//	cout<<ans<<" "<<G(id1,t1,ans+1)<<" "<<G(id2,t2,ans+1)<<" "<<id1<<" "<<id2<<" "<<t1<<" "<<t2<<"!!\n";
	assert(G(id1,t1,ans+1)!=G(id2,t2,ans+1));
	return G(id1,t1,ans+1)<G(id2,t2,ans+1);
}
char nx[xx];
void Sort(int id,vector<int>&I)
{
	I.clear();
	int len=a[id].size();
	for(int i=len-1;i>=0;i--)
	{
		if(i==len-1||a[id][i]!=a[id][i+1])nx[i]=(i==len-1?0:a[id][i+1]);
		else nx[i]=nx[i+1];
	}
	for(int i=0;i<len;i++)if(nx[i]<a[id][i])I.push_back(i);
	I.push_back(-1);
	for(int i=len-1;i>=0;i--)if(nx[i]>a[id][i])I.push_back(i);
}
//id 
int f[xx][2],sz[xx];
ll S[xx];
int main(){
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	ni=ksm(base,mod-2);
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s),a[i]=s;
		int len=strlen(s);
		sz[i]=len;
		sum[i].resize(len);
		for(int j=0;j<len;j++)sum[i][j]=((j?sum[i][j-1]:0)+pw[j]*s[j])%mod;
	}
	vector<int>lst,nw;
	int lop=0,nop=1;
	for(int i=1;i<=n;i++)
	{
		Sort(i,nw);
		for(int j=0;j<=sz[i];j++)f[j][nop]=0;
		if(i==1)
			for(int j=0;j<=sz[i];j++)f[j][nop]=1;
		else 
		{
			int lps=-1;
			for(int j=0;j<=sz[i];j++)
			{
				assert(sz[i]);
				//len 
				while(lps<sz[i-1]&&cmp(i-1,i,lst[lps+1],nw[j],sz[i-1]-1,sz[i]-1))lps++;
				f[j][nop]=(lps==-1?0:S[lps]);
//				cout<<i<<" "<<j<<" "<<f[i][nop]<<"!!\n";
			}
		}
		//-1 
		for(int j=0;j<=sz[i];j++)S[j]=((j?S[j-1]:0)+f[j][nop])%mod;
		swap(lst,nw);
		swap(lop,nop);
	}
//	cout<<
	cout<<S[sz[n]]<<"\n";
	pc('1',1);
	return 0;
}