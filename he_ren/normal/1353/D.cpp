#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

struct Seg
{
	int l,r,len;
};
inline bool cmp(const Seg &p,const Seg &q){ return p.len==q.len? p.l<q.l: p.len>q.len;}

vector<Seg> vec;

void gao(int l,int r)
{
	if(l>r) return;
	
	vec.push_back((Seg){l,r,r-l+1});
	if(l==r) return;
	
	int mid = (l+r)>>1;
	gao(l,mid-1);
	gao(mid+1,r);
}

int ans[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	vec.clear();
	gao(1,n);
	
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int l=vec[i].l, r=vec[i].r;
		int mid = (l+r)>>1;
		ans[mid] = i+1;
	}
	
	for(int i=1; i<=n; ++i)
		printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}