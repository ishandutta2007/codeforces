#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
vector<int>seg[(1<<19)];
int lim;
int inv[200005],n,q,s,le,ri;

inline void update()
{
	for(int i=((1<<18)+n)/2+1;i>=1;i--)
	{
		if(i==2 || i==6 || seg[i*2+1].size()+seg[i*2+2].size()==0) continue;
		seg[i].resize(seg[i*2+1].size()+seg[i*2+2].size());
		merge(seg[i*2+1].begin(),seg[i*2+1].end(),seg[i*2+2].begin(),seg[i*2+2].end(),seg[i].begin());
	}
}

inline int calc(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b)
	{
		int ret=upper_bound(seg[k].begin(),seg[k].end(),lim)-seg[k].begin();
		return ret;
	}
	return calc(a,b,k*2+1,l,l+(r-l+1)/2-1)+calc(a,b,k*2+2,l+(r-l+1)/2,r);
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s);
		inv[s]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;i*j<=n;j++)
		{
			seg[min(inv[i],inv[i*j])+(1<<18)-1].pb(max(inv[i],inv[i*j]));
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(seg[i+(1<<18)-1].begin(),seg[i+(1<<18)-1].end());
	}
	update();
	while(q--)
	{
		scanf("%d %d",&le,&ri);
		lim=ri-1;
		printf("%d\n",calc(le-1,ri-1,0,0,(1<<18)-1)+ri-le+1);
	}
	return 0;
}