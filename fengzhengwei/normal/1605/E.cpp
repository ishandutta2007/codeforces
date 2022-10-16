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
const int xx=2e5+5;
//Kidlt 
ll K[xx],B[xx],a[xx],b[xx],n;
ll sum0[xx],sum2[xx];
ll a0[xx],a2[xx];
ll g(ll *sum,ll *A,int sz,ll dlt)//dlt 
{
	int l=1,r=sz;
	ll ans=0;
//	if(dlt>=0)
//	{
		int re=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(A[mid]+dlt<=0)re=mid,l=mid+1;
			else r=mid-1;
		}
		ans=(-sum[re]-re*dlt)+(sum[sz]-sum[re]+dlt*(sz-re));
//	cout<<sz<<" "<<re<<"!!\n";
//	}
//	else 
//	{
//		int re=0;
//		while(l<=r)
//		{
//			int mid=l+r>>1;
//			if(A[mid]+dlt<=0)re=mid,l=mid+1;
//			else r=mid-1;
//		}
//		ans=(-sum[re]-re*dlt)+(sum[n]-sum[re]+dlt*(n-re));
//	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	//dlt 
	K[1]=1,B[1]=0;
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i+i;j<=n;j+=i)
		{
			K[j]-=K[i];
			// 
			// 
			// 
//			B[j]-=B[i];
			B[j]+=b[i]-a[i]-B[i];
			//-B[i]b[i]-a[i] 
		}
	}
	vector<ll>v[3];
	for(int i=1;i<=n;i++)assert(K[i]==1||K[i]==0||K[i]==-1);
	for(int i=1;i<=n;i++)
	{
		if(K[i]==-1)v[0].push_back(b[i]-a[i]-B[i]);
		if(K[i]==0)v[1].push_back(b[i]-a[i]-B[i]);
		if(K[i]==1)v[2].push_back(b[i]-a[i]-B[i]);
	}
	ll res=0;
	for(auto it:v[1])res+=abs(it);
	sort(v[0].begin(),v[0].end());
	sort(v[2].begin(),v[2].end());
	for(int i=1;i<=v[0].size();i++)sum0[i]=sum0[i-1]+v[0][i-1],a0[i]=v[0][i-1];
	for(int i=1;i<=v[2].size();i++)sum2[i]=sum2[i-1]+v[2][i-1],a2[i]=v[2][i-1];
//	cout<<v[0][0]<<" "<<v[2][0]<<"\n";
//	for(int i=1;i<=n;i++)cout<<K[i]<<" "<<B[i]<<"!!\n";
	int q=read();
	while(q--)
	{
		int A=read();
		ll dlt=A;
		cout<<g(sum0,a0,v[0].size(),-dlt)+g(sum2,a2,v[2].size(),dlt)+res<<"\n";
	}
	pc('1',1);
	return 0;
}