#include<cstdio>
#include<cstdlib>
#include<algorithm>
const int MAXN = 1e5 + 5;
using namespace std;

inline void error(void){ printf("-1"); exit(0);}

int ans[MAXN];

int d;
void gao(int l,int r)
{
	if(!d || l>=r-1) return;
	
	int mid = (l+r)>>1;
	d-=2;
	swap(ans[mid-1],ans[mid]);
	gao(l,mid); gao(mid,r);
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&d);
	
	--d;
	if(d&1) error();
	for(int i=0; i<n; ++i) ans[i]=i+1;
	gao(0,n);
	if(d) error();
	for(int i=0; i<n; ++i) printf("%d ",ans[i]);
	return 0;
}