#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,ans,s1;
vector<long long> seq[4];
int main()
{
	scanf("%I64d",&n);
	fz1(i,n)
	{
		char c1,c2;
		long long x=0;
		scanf(" %c%c%I64d",&c1,&c2,&x);
		seq[(c1-'0')*2+c2-'0'].push_back(x);
	}
	fz0k(i,4) {sort(seq[i].begin(),seq[i].end());reverse(seq[i].begin(),seq[i].end());}
	ff(seq[3],it)
	{
		ans+=*it;
		s1++;
	}
	for (i=0;i<seq[1].size()&&i<seq[2].size();i++)
	{
		ans+=seq[1][i]+seq[2][i];
	}
	for (;i<seq[1].size()||i<seq[2].size();i++)
	{
		if (i<seq[1].size()) seq[0].push_back(seq[1][i]);
		if (i<seq[2].size()) seq[0].push_back(seq[2][i]);
	}
	sort(seq[0].begin(),seq[0].end());reverse(seq[0].begin(),seq[0].end());
	for (i=0;i<s1&&i<seq[0].size();i++) ans+=seq[0][i];
	cout<<ans<<endl;
	return 0;
}