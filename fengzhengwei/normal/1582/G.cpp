#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc//
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
int vis[xx],prim[xx],mn[xx];
void pre(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
			mn[i]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}
int a[xx],M[xx];
int Mn[xx<<2];
void pd(int x)
{
	Mn[x<<1]=min(Mn[x<<1],Mn[x]);
	Mn[x<<1|1]=min(Mn[x<<1|1],Mn[x]);
}
void cov(int k,int l,int r,int x,int y,int z)
{
//	cout<<x<<" "<<y<<" "<<z<<"\n";
	if(x>y)return ;
	if(x<=l&&r<=y)return Mn[k]=min(Mn[k],z),void();
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cov(k<<1,l,mid,x,y,z);
	if(mid<y)cov(k<<1|1,mid+1,r,x,y,z);
}
ll ans;
int n;
void get(int k,int l,int r)
{
	if(l==r)
	{
//		cout<<l<<" "<<Mn[k]<<"\n";
		Mn[k]=min(Mn[k],n);
		ans+=Mn[k]-l+1;
		return ;
	}
	pd(k);
	int mid=l+r>>1;
	get(k<<1,l,mid);
	get(k<<1|1,mid+1,r);
}
char s[xx];
vector<int>v[xx];
int stk[xx],qz[xx];
int main(){
	memset(Mn,0x3f,sizeof(Mn));
	pre(1000000);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int o=a[i],mx=0;
		while(o!=1)
		{
			mx=max(mx,mn[o]);
			int s=mn[o];
			while(o%s==0)o/=s;
			v[s].push_back(i);
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		if(v[i].size())
		{
			int top=0;//0 
			stk[++top]=0;
			for(int j=1;j<=v[i].size();j++)//j-1 
			{
				int tt=0;
				while(a[v[i][j-1]]%i==0)a[v[i][j-1]]/=i,tt++;
				if(s[v[i][j-1]]=='*')qz[j]=qz[j-1]+tt;
				else qz[j]=qz[j-1]-tt;
				while(top&&qz[stk[top]]>qz[j])top--;
				if(!top)cov(1,1,n,1,v[i][j-1],v[i][j-1]-1);
				else cov(1,1,n,v[i][stk[top]]+1,v[i][j-1],v[i][j-1]-1);// 
//				if(v[i][j-1]==2)
//				{
//					cout<<v[i][stk[top]]+1<<" ss "<<i<<"!!!\n";
//				}
				stk[++top]=j;
			}
		}
	}
	get(1,1,n);
	cout<<ans<<"\n";
	return 0;
}