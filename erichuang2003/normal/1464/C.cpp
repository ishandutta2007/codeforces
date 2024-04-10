#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n;
int cnt[27];

ll T;
ll w[27];

char s[MAXN];

int main()
{
	scanf("%d%lld%s",&n,&T,s + 1);
	w[0] = 1;
	for (int i = 1;i <= 26;i++)
		w[i] = w[i - 1] * 2;
	T -= w[s[n] - 'a'];
	T += w[s[n - 1] - 'a'];
	for (int i = 1;i <= n - 2;i++)
		T -= w[s[i] - 'a'];
	if (T > 0)
	{
		puts("No");
		return 0;
	}
	T = -T;
	for (int i = 1;i <= n - 2;i++)
		cnt[s[i] - 'a' + 1]++;
	for (int i = 26;i >= 0;i--)
		while (cnt[i] && T >= w[i])
		{
			T -= w[i];
			cnt[i]--;
		}
	puts(!T ? "Yes" : "No");
	return 0;
}