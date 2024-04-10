#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;int n,maxn,a[N];
vector<int>G[N];int tree[N];
int lowbit(int x){return (x&(-x));}
void add(int x,int k)
{
	for(int i=x;i<=maxn;i+=lowbit(i))tree[i]=max(tree[i],k);
}
int qry(int x)
{	
	int sum=0;
	for(int i=x;i;i-=lowbit(i))sum=max(sum,tree[i]);
	return sum;
}
signed main()
{
	scanf("%d",&n),maxn=n+5;
	for(int i=1;i<=n+1;++i)G[i].push_back(0);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),G[a[i]].push_back(i);
	for(int i=1;i<=n+1;++i)G[i].push_back(n+1);
	int ans=1;
	for(int i=1;i<=n+1;++i)
	{
		int flag=0,sz=G[i].size();
		if(sz==n+2){ans=i;break;}
		for(int j=1;j<sz;++j)
		{
			int f=qry(G[i][j-1]+1);
			if(f<G[i][j])flag=1;
		}
		if(!flag) break;
		for(int j=1;j<sz;++j)
		{
			int f=G[i][j-1]+1;
			add(f,G[i][j]);	
		} ans=i+1;
	}
	cout<<ans<<endl;
	return 0;
}