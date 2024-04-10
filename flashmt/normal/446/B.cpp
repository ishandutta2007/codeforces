#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int m, n, k, p;
long long fCol[1000100], fRow[1000100];

void solve(vector <int> a, int sz, long long f[])
{
	priority_queue <int> q;
	for (int i = 0; i < int(a.size()); i++) q.push(a[i]);
	
	f[0] = 0;
	for (int turn = 1; turn <= k; turn++)
	{
		int x = q.top();
		q.pop();
		f[turn] = f[turn - 1] + x;
		q.push(x - sz * p);
	}		
}

int main()
{
	ios::sync_with_stdio(0);
	int x;
	cin >> m >> n >> k >> p;
	
	vector <int> row(m, 0), col(n, 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			row[i] += x;
			col[j] += x;
		}
		
	solve(row, n, fRow);
	solve(col, m, fCol);
	
	long long ans = -oo;
	for (int rowOperations = 0; rowOperations <= k; rowOperations++)
	{
		int colOperations = k - rowOperations;
		long long res = fRow[rowOperations] + fCol[colOperations];
		res -= 1LL * rowOperations * colOperations * p;
		ans = max(ans, res);
	}
	
	cout << ans << endl;
}