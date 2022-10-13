#include <bits/stdc++.h>
using namespace std;

double f[2222][2222];
int visited[2222][2222], n;
set <int> rows, columns;

double dp(int rows, int cols)
{
	if (rows == n && cols == n) return 0;
	
	if (visited[rows][cols]) return f[rows][cols];
	visited[rows][cols] = 1;
	
	if (rows < n && cols < n) f[rows][cols] += (dp(rows + 1, cols + 1) + 1) * (n - rows) * (n - cols);
	if (cols < n) f[rows][cols] += (dp(rows, cols + 1) + 1) * rows * (n - cols);
	if (rows < n) f[rows][cols] += (dp(rows + 1, cols) + 1) * (n - rows) * cols;
	f[rows][cols] += rows * cols;
	f[rows][cols] /= (n * n - rows * cols);
	
	return f[rows][cols];
}

int main()
{
	int m, x, y;
	cin >> n >> m;
	while (m--)
	{
		cin >> x >> y;
		rows.insert(x);
		columns.insert(y);
	}
	
	printf("%.6lf\n", dp(rows.size(), columns.size()));
}