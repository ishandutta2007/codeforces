#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 2e5 + 5;
const int lb = 17;
const int LB = lb + 2;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

bool a[MAXM];
int sum[MAXM];
inline int get_sum(int l,int r){ return sum[r] - sum[l-1];}

int f[MAXM][LB];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		a[x] ^= 1;
	}
	
	for(int i=1; i<=m; ++i) sum[i] = sum[i-1] + a[i];
	for(int i=m; i>=1; --i)
		for(int k=1; i+(1<<k)-1<=m; ++k)
		{
			f[i][k] = f[i][k-1] ^ f[i+bbit(k-1)][k-1];
			if(get_sum(i+bbit(k-1),  i+bbit(k)-1) & 1)
				f[i][k] ^= bbit(k-1);
		}
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		int res = 0;
		for(int i=lb; i>=0; --i) if(l+(1<<i)-1 <= r)
		{
			res ^= f[l][i];
			if(get_sum(l+(1<<i), r) & 1)
				res ^= bbit(i);
			l += 1<<i;
		}
		
		putchar(res? 'A': 'B');
	}
	return 0;
}