//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
char s[200111];
const int B = 100;
int n;
ll ans = 0;
int a[200111];
unordered_map<int, int> cnt;
void solve_small(int len)
{
	cnt.clear();
	for (int i=n; i>=0; i--)
	{
		int cur = i-len*a[i];
		int &v = cnt[cur];
		ans += v;
		v++;
	}
}
pair<int,int> seg[200111];
int main()
{
	scanf("%s", s+1);
	n = strlen(s+1);
	for (int i=1; i<=n; i++) a[i] += a[i-1]+(s[i]=='1');
	for (int l=1; l<=n&&l<=B; l++)
	{
		solve_small(l);
	}
	cerr<<"ans="<<ans<<endl;
	for (int i=0; i<=n; i++) seg[i] = MP(n, 0);
	for (int i=0; i<=n; i++)
	{
		seg[a[i]].FF = min(seg[a[i]].FF, i);
		seg[a[i]].SS = max(seg[a[i]].SS, i);
	}
	for (int i=0; i<=n; i++)
	{
		int l = i, j = a[i];
		while (true)
		{
			j++;
			l += B+1;
			if (j>n||l>n) break;
			if (seg[j].FF<=seg[j].SS&&l<=seg[j].SS)
			{
				int tl = (l>=seg[j].FF?0:(seg[j].FF-l+j-a[i]-1)/(j-a[i]));
				int tr = (seg[j].SS-l)/(j-a[i]);
				ans += tr-tl+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}