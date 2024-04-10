#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<20) + 5;
const int M = (1<<20) - 1;

inline int calc(int n,int m)
{
	if(m <= 0) return n == 0? 1: 0;
	if(n < m) return 0;
	assert(n > 0 && m > 0);
	return ((n-1) & (m-1)) == (m-1);
}

int a[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int ans[M+5];
	for(int i=1; i<=n; ++i)
	{
		int sum = 0;
		for(int j=i; j<=n; ++j)
		{
			if(j>i) sum += a[j];
			if(sum >= 20) break;
			if((M >> sum) < a[i]) break;
			
			int has = (i>1) + (j<n);
			ans[a[i] << sum] ^= calc(n-1-(j-i)-has, d-has);
		}
	}
	
	int pos = M;
	while(pos>0 && !ans[pos]) --pos;
	while(pos>=0) putchar(ans[pos--] + '0');
	return 0;
}