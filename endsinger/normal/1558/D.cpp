#include<bits/stdc++.h>
using namespace std;
const int N=400005,mod=998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int n,m,fc[N],iv[N],x[N],y[N],t,b[N],vis[N];
int c(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
vector<int>v;
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]);
	t=0,v.clear();
	for(int i=m;i>=1;i--)
	{
		int l=y[i],r=n,p=1e9;
		while(l<=r)
		{
			int mid=l+r>>1;
			int f=ask(mid);
			if(mid-f<y[i]){l=mid+1;continue;}
			if(mid-f>y[i]){r=mid-1;continue;}
			p=min(p,mid);
			r=mid-1;
		}
		if(!vis[p+1])
			t++;
		add(p,1);
		v.push_back(p);
		vis[p]=1;
	}
	printf("%d\n",c(n+n-1-t,n));
	for(auto i:v)
		add(i,-1),vis[i]=0;
}
int main()
{
	srand((unsigned long long)new char);
	fc[0]=iv[0]=1;
	for(int i=1;i<=400000;i++)
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}