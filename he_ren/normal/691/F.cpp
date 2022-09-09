#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
const int MAXP = 3e6 + 1;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int cnt[MAXP];
ll ans[MAXP];
int p[MAXM];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
		scanf("%d",&p[i]);
	int maxp=0;
	for(int i=1; i<=m; ++i) chk_max(maxp,p[i]);
	
	for(int i=1; i<=maxp; ++i) if(cnt[i])
	{
		int maxj=maxp/i;
		ll cnti=cnt[i];
		for(int j=1; j<=maxj; ++j) if(cnt[j])
			ans[j*i] += cnti*cnt[j];
	}
	int sp=sqrt(maxp);
	for(int i=1; i<=sp; ++i) ans[i*i]-=cnt[i];
	
	for(int i=1; i<=maxp; ++i) ans[i]+=ans[i-1];
	
	ll all=(ll)n*(n-1);
	for(int i=1; i<=m; ++i) cout<<all-ans[p[i]-1]<<endl;
	return 0;
}