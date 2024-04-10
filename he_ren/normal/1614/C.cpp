#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

ll pw2[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector< vector<int> > p(m);
	for(int i=1; i<=m; ++i)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		p[i-1] = {l,r,x};
	}
	
	int ans = 0;
	for(int k=0; k<=30; ++k)
	{
		bool has = 0;
		for(vector<int> &t: p)
			if(bdig(t[2], k))
				has = 1;
		
		if(!has) continue;
		ans = (ans + pw2[k] * pw2[n-1]) %mod;
	}
	printf("%d\n",ans);
}

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}