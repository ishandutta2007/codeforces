#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];
bool ans[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int freq[MAXN];
	for(int i=1; i<=n; ++i) freq[i] = 0;
	for(int i=1; i<=n; ++i) ++freq[a[i]];
	
	for(int i=1; i<=n; ++i) ans[i] = 0;
	ans[1] = 1;
	for(int i=1; i<=n; ++i)
		if(!freq[i]){ ans[1] = 0; break;}
	
	for(int i=n, l=1, r=n; i>1; --i)
	{
		int k = n-i+1;
		if(!freq[k]) break;
		ans[i] = 1;
		if((a[l] == k) + (a[r] == k) != 1 || freq[k] != 1) break;
		--freq[k];
		if(a[l] == k) ++l;
		else --r;
	}
	
	for(int i=1; i<=n; ++i) putchar(ans[i] + '0');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}