#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<bool,int> pbi;
const int MAXN = 2e5 + 5;

int n,d;
int a[MAXN];

int dsc[MAXN*2], dcnt=0;

int check(int mid)
{
	dcnt = 0;
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = max((ll)1, (ll)a[i]-mid),
		dsc[++dcnt] = min((ll)1e9, (ll)a[i]+mid);
	
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1)-dsc-1;
	
	static int dif[MAXN*2];
	for(int i=1; i<=dcnt; ++i) dif[i] = 0;
	
	for(int i=1; i<=n; ++i)
	{
		int lef = lower_bound(dsc+1,dsc+dcnt+1, max((ll)1, (ll)a[i]-mid)) - dsc;
		int rig = lower_bound(dsc+1,dsc+dcnt+1, min((ll)1e9, (ll)a[i]+mid)) - dsc;
		++dif[lef]; --dif[rig+1];
	}
	
	for(int i=1; i<=dcnt; ++i)
	{
		dif[i] += dif[i-1];
		if(dif[i] >= d) return dsc[i];
	}
	return 0;
}

void solve(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	++d;
	
	int l=0, r=1e9;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",check(l));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}