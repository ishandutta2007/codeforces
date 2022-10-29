#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,pr[N],a[N],ans;

int mp[1200005],vis[1200005];

void Prime(int x)
{
		int i;
		for (i=2;i*i<=x;++i)
				while (x%i==0) pr[++pr[0]]=i,x/=i;
		if (x>1) pr[++pr[0]]=x;
}

int dfs(int x)
{
		if (!x) return 0;
		if (vis[x]) return mp[x];
		vis[x]=1;
//		if (mp.find(x)!=mp.end()) return mp[x];
		int ans=0,i,mex[45];
		for (i=0;i<45;++i) mex[i]=0;
		for (i=1;x>=(1<<i);++i)
		{
				int p=(x&((1<<i)-1))|(x>>i);
				if (p&1) --p;
				mex[dfs(p)]=1;
		}
		for (i=0;mex[i];++i); 
		return mp[x]=i;
}

int Dfs(int x)
{
		if (x<1048576) return mp[x]; 
		int i,mex[45];
		for (i=0;i<45;++i) mex[i]=0;
		for (i=1;x>=(1<<i);++i)
		{
				int p=(x&((1<<i)-1))|(x>>i);
				if (p&1) --p;
				mex[Dfs(p)]=1;
		}
		for (i=0;mex[i];++i); 
		return i;
}

int mex[105];

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]),Prime(a[i]);
	sort(pr+1,pr+pr[0]+1); pr[0]=unique(pr+1,pr+pr[0]+1)-(pr+1);
	for (i=0;i<(1<<20);++i) dfs(i); 
	for (i=1;i<=pr[0];++i)
	{
			 int now=0;
			 for (j=1;j<=n;++j)
			 {
			 		 int s=0;
			 		 while (a[j]%pr[i]==0) a[j]/=pr[i],++s;
					 now|=(1<<s); 
			 }
			 if (now&1) --now;
			 ans^=Dfs(now); 
	}
	if (!ans) printf("Arpa"); else printf("Mojtaba");
}