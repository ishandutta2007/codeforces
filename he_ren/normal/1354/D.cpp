#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

int n;

int tree[MAXN];
#define lowbit(x) ((x)&-(x))
inline void update(int x)
{
	while(x<=n)
		++tree[x],
		x+=lowbit(x);
}
inline void erase(int x)
{
	while(x<=n)
		--tree[x],
		x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)
		res += tree[x],
		x^=lowbit(x);
	return res;
}

inline int kth(int k)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(query(mid)>=k) r=mid;
		else l=mid+1;
	}
	return l;
}

int a[MAXN];

int main(void)
{
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		update(a[i]);
	
	int tot = n;
	for(int i=1; i<=Q; ++i)
	{
		int d;
		scanf("%d",&d);
		if(d<0) erase(kth(-d)), --tot;
		else update(d), ++tot;
	}
	
	if(!tot) printf("0");
	else printf("%d",kth(1));
	return 0;
}