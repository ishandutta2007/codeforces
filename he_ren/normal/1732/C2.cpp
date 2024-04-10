#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];
ll sum1[MAXN];
int sum2[MAXN];

int nxt[MAXN], pre[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		sum1[i] = sum1[i-1] + a[i];
		sum2[i] = sum2[i-1] ^ a[i];
	}
	
	for(int i=1; i<=n; ++i)
		pre[i] = a[i] == 0? pre[i-1]: i;
	nxt[n+1] = n+1;
	for(int i=n; i>=1; --i)
		nxt[i] = a[i] == 0? nxt[i+1]: i;
	
	auto calc = [&] (int l,int r) -> ll
	{
		if(l>r) return -1;
		return (sum1[r] - sum1[l-1]) - (sum2[r] ^ sum2[l-1]);
	};
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		ll need = calc(l,r);
		if(!need)
		{
			printf("%d %d\n",l,l);
			continue;
		}
		
		int i = l, j = r;
		while(pre[j-1] >= l && calc(l, pre[j-1]) == need)
			j = pre[j-1];
		
		int al = l, ar = r;
		while(1)
		{
			if(calc(i, r) != need) break;
			while(calc(i, j) != need)
				j = min(r, nxt[j+1]);
			
			if(j-i < ar-al)
				al = i, ar = j;
			
			i = nxt[i+1];
		}
		
		printf("%d %d\n",al,ar);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}