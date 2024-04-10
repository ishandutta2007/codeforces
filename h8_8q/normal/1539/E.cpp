#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mid ((l+r)>>1)

inline int read()
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-'0';c=getchar();}
	return res;
}

const int N=1e5+5;
int n,m,a[N],l1[N],r1[N],l2[N],r2[N],nex[N][2],sm[N][2],dp[N][2],pre[N][2],ans[N];
int mn1[N][20],mn2[N][20],mx1[N][20],mx2[N][20];

vector<int> upd[N][2];
set<int> hav[2];

inline int queryl1(int l,int r){int k=log2(r-l+1);return max(mx1[l][k],mx1[r-(1<<k)+1][k]);}
inline int queryl2(int l,int r){int k=log2(r-l+1);return max(mx2[l][k],mx2[r-(1<<k)+1][k]);}
inline int queryr1(int l,int r){int k=log2(r-l+1);return min(mn1[l][k],mn1[r-(1<<k)+1][k]);}
inline int queryr2(int l,int r){int k=log2(r-l+1);return min(mn2[l][k],mn2[r-(1<<k)+1][k]);}

void print(int x,int y)
{
	if(x==0) return;
	for(int i=pre[x][y];i<=x;++i)
		ans[i]=y;
	print(pre[x][y]-1,y^1);
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		l1[i]=read();r1[i]=read();
		l2[i]=read();r2[i]=read();
		mx1[i][0]=l1[i];mx2[i][0]=l2[i];
		mn1[i][0]=r1[i];mn2[i][0]=r2[i];
		sm[i][0]=sm[i-1][0]+(a[i]>=l1[i]&&a[i]<=r1[i]);
		sm[i][1]=sm[i-1][1]+(a[i]>=l2[i]&&a[i]<=r2[i]);
	}
	for(int i=1;i<=17;++i)
		for(int j=1;j<=n;++j)
		{
			mn1[j][i]=min(mn1[j][i-1],mn1[j+(1<<(i-1))][i-1]);
			mn2[j][i]=min(mn2[j][i-1],mn2[j+(1<<(i-1))][i-1]);
			mx1[j][i]=max(mx1[j][i-1],mx1[j+(1<<(i-1))][i-1]);
			mx2[j][i]=max(mx2[j][i-1],mx2[j+(1<<(i-1))][i-1]);
		}
	for(int i=1;i<=n;++i)
	{
		int l=i,r=n;
		nex[i][0]=i-1;
		while(l<=r)
		{
			if(sm[mid][0]-sm[i-1][0]==mid-i+1&&queryl2(i,mid)<=a[i-1]&&a[i-1]<=queryr2(i,mid))
				nex[i][0]=mid,l=mid+1;
			else r=mid-1;
		}
		l=i;r=n;
		nex[i][1]=i-1;
		while(l<=r)
		{
			if(sm[mid][1]-sm[i-1][1]==mid-i+1&&queryl1(i,mid)<=a[i-1]&&a[i-1]<=queryr1(i,mid))
				nex[i][1]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	dp[0][0]=dp[0][1]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=1;++j)
		{
			if(i>1) dp[i][j]+=dp[i-1][j];
			for(int k=0;k<upd[i][j].size();++k)
				if(upd[i][j][k]>0) hav[j].insert(upd[i][j][k]);
				else hav[j].erase(hav[j].find(-upd[i][j][k]));
			if(dp[i][j])
			{
				if(i!=0) pre[i][j]=*hav[j].begin();
				int l=i+1,r=nex[i+1][j^1];
				if(l>r) continue;
				dp[l][j^1]++;dp[r+1][j^1]--;
				upd[l][j^1].push_back(i+1);
				upd[r+1][j^1].push_back(-i-1);
			}
		}
	if(dp[n][0]||dp[n][1])
	{
		if(dp[n][0]) print(n,0);
		else print(n,1);
		printf("Yes\n");
		for(int i=1;i<=n;++i)
			printf("%lld ",ans[i]);
	}
	else printf("No\n");
	return 0;
}