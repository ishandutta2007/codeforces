#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, m, t[333];
long long d, a[333], b[333], f[2][150150];
long long happiness[150150], sumRight[150150], sumLeft[150150], st[150150];
int cntRight[150150], cntLeft[150150], pos[150150], head, tail;

void calcHappiness(int l, int r)
{
	for (int i = 1; i <= n; i++) 
	{
		happiness[i] = 0;
		sumRight[i] = sumLeft[i] = 0;
		cntRight[i] = cntLeft[i] = 0;
	}
	
	for (int i = l; i <= r; i++)
	{
		happiness[a[i]] -= b[i];
		sumRight[a[i]] += b[i];
		cntRight[a[i]]++;
		sumLeft[a[i]] += b[i];
		cntLeft[a[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		sumRight[i] += sumRight[i - 1];
		cntRight[i] += cntRight[i - 1];
		happiness[i] += sumRight[i];
		sumRight[i] -= cntRight[i];
	}
	
	for (int i = n; i; i--)
	{
		sumLeft[i] += sumLeft[i + 1];
		cntLeft[i] += cntLeft[i + 1];
		happiness[i] += sumLeft[i];
		sumLeft[i] -= cntLeft[i];
	}
}

void push(long long val, int id)
{
	while (tail >= head && val >= st[tail]) tail--;
	st[++tail] = val;
	pos[tail] = id;
}

long long pop(int leftEnd)
{
	while (pos[head] < leftEnd) head++;
	return st[head];
}

int main()
{
	ios::sync_with_stdio(0);
	//freopen("c.in", "r", stdin);
	
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> t[i];
	
	int z = 0, lastDay = 0;
	for (int l = 1; l <= m; )
	{
		int r = l, curDay = t[l];
		while (r + 1 <= m && t[r + 1] == curDay) r++;
		int range = int(min(1LL * n, (curDay - lastDay) * d));
		
		z ^= 1;
		calcHappiness(l, r);
		
		head = 1; 
		tail = 0;
		for (int i = 1; i <= range; i++) push(f[z ^ 1][i], i);
		
		for (int i = 1; i <= n; i++)
		{
			if (i + range <= n) push(f[z ^ 1][i + range], i + range);
			f[z][i] = pop(i - range) + happiness[i];
		}
		
		l = r + 1;
		lastDay = curDay;
	}
	
	long long ans = -oo;
	for (int i = 1; i <= n; i++) ans = max(ans, f[z][i]);
	cout << ans << endl;
}