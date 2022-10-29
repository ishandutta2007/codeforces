#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int n, a[N], b[N], cnt;

void Main()
{
	cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i) if (a[i] == b[i] - 1) ++cnt;
	else if (a[i] != b[i]) cnt = 1000000000;
	if (cnt > n) puts("NO");
	else puts("YES"); 
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main(); 
}