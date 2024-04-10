#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];

int c[MAXN], num[MAXN];
int cnt[MAXN], lef[MAXN], rig[MAXN], f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int m = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		c[++m] = a[i]; num[m] = j-i;
	}
	
	static int freq[MAXN];
	for(int i=m; i>=1; --i)
	{
		freq[c[i]] += num[i];
		cnt[i] = freq[c[i]];
	}
	
	for(int i=m; i>=1; --i) lef[c[i]] = i;
	for(int i=1; i<=m; ++i) rig[c[i]] = i;
	
	int ans = 0;
	for(int i=1; i<=m; ++i)
	{
		f[i] = max(f[i], f[i-1]);
		chk_max(ans, f[i-1] + cnt[i]);
		
		if(i == lef[c[i]])
			chk_max(f[rig[c[i]]], f[i-1] + cnt[i]);
	}
	chk_max(ans, f[m]);
	
	printf("%d",n-ans);
	return 0;
}