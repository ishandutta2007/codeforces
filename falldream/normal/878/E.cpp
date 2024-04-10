#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define MN 100000
#define mod 1000000007
#define INF (long long)4e18
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> q[MN+5];long long act[MN+5];
int pw[MN+5],inv[MN+5],top=0,n,m,a[MN+5],Ans[MN+5],s[MN+5],p[MN+5];
vector<pair<int,int> >v[MN+5];
inline int Calc(int l,int r){return 1LL*(s[r]-s[l-1]+mod)*inv[l]%mod;}
inline void add(long long&x,long long y){x=min(x+y,INF);}
inline void pow(long long&x,int t){for(int i=1;i<=t&&x<INF;++i) x=min(INF,x*2);}
int main()
{
  	n=read();m=read();pw[0]=inv[0]=1;
  	for(int i=1;i<=n;++i) a[i]=read(),pw[i]=2*pw[i-1]%mod,inv[i]=1LL*inv[i-1]*(mod+1)/2%mod,s[i]=(s[i-1]+(a[i]+2LL*mod)*pw[i])%mod; 
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		v[r].push_back(make_pair(l,i));	
	}
	for(int i=1;i<=n;++i)
	{
		long long x=a[i];int l=i,r=i;
		for(;top&&x>=0;--top)
		{
			l=q[top].first;
			if(x>0) pow(x,q[top].second-q[top].first+1);
			add(x,act[top]);
		}
		q[++top]=make_pair(l,r);p[top]=(p[top-1]+Calc(l,r))%mod;act[top]=x;
		for(int j=0;j<v[i].size();++j)
		{
			int pos=upper_bound(q+1,q+top+1,make_pair(v[i][j].first,n+1))-q-1;
			//cout<<v[i][j].second<<" pos= "<<pos<<endl;
			int ans=(1LL*p[top]-p[pos]+Calc(v[i][j].first+1,q[pos].second)+mod)%mod;
			Ans[v[i][j].second]=(2LL*ans+a[v[i][j].first]+2*mod)%mod;	
		}
	//	cout<<"finish"<<i<<endl;
	//	for(int j=1;j<=top;++j) printf("%d %d %d %lld\n",q[j].first,q[j].second,p[j],act[j]);
	}
	for(int i=1;i<=m;++i) printf("%d\n",Ans[i]);
	return 0;
}