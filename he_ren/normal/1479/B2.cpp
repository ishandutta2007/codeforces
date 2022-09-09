#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	n = unique(a+1,a+n+1) - a - 1;
	if(n == 1) return printf("1"), 0;
	
	static int f[MAXN];
	memset(f,0x3f,sizeof(f));
	f[0] = 1;
	int fir = 1, sec = inf, tag = 0;
	for(int i=2; i<=n; ++i)
	{
		int mn = f[a[i]] + tag;
		int mn2 = (fir == f[a[i]]? sec: fir) + tag + 1;
		mn = min(mn, mn2);
		
		++tag;
		int lst = f[a[i-1]] = min(f[a[i-1]], mn - tag);
		if(lst < fir) sec = fir, fir = lst;
		else if(lst < sec) sec = lst;
	}
	
	printf("%d",fir + tag);
	return 0;
}