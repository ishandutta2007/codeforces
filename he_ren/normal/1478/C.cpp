#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

ll a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	int m = n * 2;
	for(int i=1; i<=m; ++i) scanf("%lld",&a[i]);
	
	sort(a+1,a+m+1);
	for(int i=1; i<=m; ++i)
	{
		if(a[i]%2){ printf("NO\n"); return;}
		a[i] /= 2;
	}
	
	for(int i=m-1; i>=1; i-=2)
	{
		if(a[i] != a[i+1]){ printf("NO\n"); return;}
		if(i == m-1)
		{
			if(a[i] % n){ printf("NO\n"); return;}
			b[n] = a[i] / n;
			continue;
		}
		if(a[i+2] == a[i]){ printf("NO\n"); return;}
		
		int pos = (i+1) / 2;
		if((a[i+2] - a[i]) % pos){ printf("NO\n"); return;}
		b[pos] = b[pos+1] - (a[i+2] - a[i]) / pos;
		
		if(b[pos] <= 0){ printf("NO\n"); return;}
	}
	
	ll sum = 0;
	for(int i=1; i<=n; ++i) sum += b[i];
	if(a[1] != sum){ printf("NO\n"); return;}
	
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}