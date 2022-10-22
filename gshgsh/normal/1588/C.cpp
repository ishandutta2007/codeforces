#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffffffffffff
#define MAXN 300001
int T,N,a[MAXN],lg2[MAXN],r[MAXN];ll sum[2][MAXN],mx[2][20][MAXN],mn[2][20][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll getmx(int t,int l,int r){int k=lg2[r-l+1];return max(mx[t][k][l],mx[t][k][r-(1<<k)+1]);}
ll getmn(int t,int l,int r){int k=lg2[r-l+1];return min(mn[t][k][l],mn[t][k][r-(1<<k)+1]);}
bool check1(int l,int x){return getmn(1,l,x)-sum[1][l-1]+sum[0][l-1]>=0;}
bool check2(int l,int x){return -getmx(0,l,x)-sum[0][l-1]+sum[1][l-1]>=0;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();lg2[1]=0;For(i,2,N)lg2[i]=lg2[i>>1]+1;For(i,1,N)sum[0][i]=sum[1][i]=0;
		For(i,1,N)sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1],sum[i&1][i]+=a[i];
		For(i,1,N)mx[i&1][0][i]=sum[1][i]-sum[0][i],mn[i&1][0][i]=sum[1][i]-sum[0][i];
		For(i,1,N)mx[i+1&1][0][i]=-INF,mn[i+1&1][0][i]=INF;
		For(t,0,1)for(int j=1;(1<<j)<=N;j++)For(i,1,N-(1<<j)+1)mx[t][j][i]=max(mx[t][j-1][i],mx[t][j-1][i+(1<<(j-1))]),mn[t][j][i]=min(mn[t][j-1][i],mn[t][j-1][i+(1<<(j-1))]);
		For(i,1,N)
		{
			int l1=i>>1,r1=N-1>>1,pos1=l1-1;while(l1<=r1){int mid=l1+r1>>1;if(check1(i,mid<<1|1))pos1=mid,l1=mid+1;else r1=mid-1;}
			int l2=i+1>>1,r2=N>>1,pos2=l2-1;while(l2<=r2){int mid=l2+r2>>1;if(check2(i,mid<<1))pos2=mid,l2=mid+1;else r2=mid-1;}
			r[i]=max(max(min(pos1<<1|1,pos2<<1|1),min(pos1+1<<1,pos2<<1)),i);
		}
		map<ll,vector<int>>mp;
		ll ans=0;FOR(i,N,1){mp[sum[1][i]-sum[0][i]].push_back(i);if(!mp[sum[1][i-1]-sum[0][i-1]].empty())ans+=mp[sum[1][i-1]-sum[0][i-1]].size()-(lower_bound(mp[sum[1][i-1]-sum[0][i-1]].begin(),mp[sum[1][i-1]-sum[0][i-1]].end(),r[i],greater<int>())-mp[sum[1][i-1]-sum[0][i-1]].begin());}
		cout<<ans<<'\n';
	}
	return 0;
}