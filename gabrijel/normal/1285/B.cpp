#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;

int niz[maxn];
long long int pref[maxn];

int main()
{
	int t;
	cin >> t;
	REP(tt, 0, t)
	{
	int n;
	cin >> n;
	REP(i, 0, n)
	{
		scanf("%d", &niz[i]);
		pref[i] = niz[i];
	}
	long long int mini = 0;
	int gdje = -1;
	long long int maxi = 0;
	REP(i, 0, n)
	{
		if(i == 0)
		{
			maxi = pref[i];
			if(pref[i] <= mini)
			{
				mini = pref[i];
				gdje = i;
			}
			continue;
		}
		pref[i] += pref[i - 1];
		if(!(i == n - 1 && gdje == -1)) maxi = max(maxi, pref[i] - mini);
		if(pref[i] <= mini) {mini = pref[i]; gdje = i;}
	}
	if(maxi >= pref[n - 1])
	{
		printf("NO\n");
	}
	else printf("YES\n");
	}
	return 0;
}