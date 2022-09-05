//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int tn, n, k;
char s[2011], t[2011];
void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	k--;
	for (int i=1; i<=k; i++) t[i*2-1] = '(', t[i*2] = ')';
	for (int i=k*2+1; i<=n; i++) t[i] = i<=n-(n/2-k)?'(':')';
	vector<pair<int,int> > v;
	for (int i=1; i<=n; i++)
	{
		if (s[i]!=t[i])
		{
			for (int j=i+1; j<=n; j++)
			{
				if (s[j]==t[i])
				{
					v.PB(MP(i, j));
					reverse(s+i, s+j+1);
					break;
				}
			}
		}
	}
	printf("%d\n", v.size());
	for (auto x : v) printf("%d %d\n", x.FF, x.SS);
}

int main()
{
	scanf("%d", &tn);
	while (tn--)
	{
		solve();
	}
	return 0;
}