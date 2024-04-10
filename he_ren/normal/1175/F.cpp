#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

inline ll rnd(void){ return ((ll)rand()<<45) | ((ll)rand()<<30) | (rand()<<15) | rand();}

int n;
int a[MAXN];
ll val[MAXN], pval[MAXN], pre[MAXN];

inline int get_res(void)
{
	for(int i=1; i<=n; ++i) pre[i] = pre[i-1] ^ val[a[i]];
	
	int res = 0;
	for(int i=1; i<=n; ++i) if(a[i] == 1)
	{
		int mx = 1;
		for(int j=i+1; j<=n && a[j] != 1; ++j)
		{
			mx = max(mx, a[j]);
			if(j-mx+1 < 1) continue;
			if((pre[j] ^ pre[j-mx]) == pval[mx]) ++res;
		}
	}
	return res;
}

int main(void)
{
	srand((unsigned long long)new char);
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) val[i] = rnd();
	for(int i=1; i<=n; ++i) pval[i] = pval[i-1] ^ val[i];
	
	int ans = count(a+1,a+n+1, 1);
	ans += get_res();
	reverse(a+1,a+n+1);
	ans += get_res();
	
	printf("%d",ans);
	return 0;
}