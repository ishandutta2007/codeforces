#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

bool isnp[MAXN];
int pri[MAXN], pcnt = 0;
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i*pri[j] <= n; ++j)
		{
			isnp[i*pri[j]] = 1;
			if(!(i%pri[j])) break;
		}
	}
}

vector<pii> ans;
inline void push_ans(int u,int v){ ans.push_back(make_pair(u,v));}

int main(void)
{
	sieve(MAXN-1);
	
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<n; ++i) push_ans(i, i+1);
	push_ans(n, 1);
	
	int mid = n >> 1, p = *lower_bound(pri+1,pri+pcnt+1,n);
	for(int i=1; i<=mid && (int)ans.size()<p; ++i)
		push_ans(i, mid + i);
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}