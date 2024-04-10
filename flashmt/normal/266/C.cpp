#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010][1010], row[1010], col[1010], cntRow[1010], cntCol[1010];
vector < pair<int,int> > res;
vector <int> type;

int main()
{
	int n, x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) row[i] = col[i] = i;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		cntRow[x]++; 
		cntCol[y]++;
		a[x][y] = 1;
	}
	
	for (int i = n; i > 1; i--)
	{
		int emptyCol = 0;
		for (int j = 1; j <= i; j++)
			if (!cntCol[col[j]])
			{
				emptyCol = j; break;
			}
		if (emptyCol && emptyCol != i)
		{
			swap(col[i], col[emptyCol]);
			type.push_back(2);
			res.push_back(make_pair(i, emptyCol));
		}
			
		int mostRow, best = 0;
		for (int j = 1; j <= i; j++)
			if (cntRow[row[j]] > best)
			{
				best = cntRow[row[j]];
				mostRow = j;
			}
			
		if (best && mostRow != i)
		{
			swap(row[i], row[mostRow]);
			type.push_back(1);
			res.push_back(make_pair(i, mostRow));
		}
		
		for (int j = 1; j <= i; j++)
			if (a[row[i]][j]) cntCol[j]--;
	} 
	
	cout << type.size() << endl;
	for (int i = 0; i < int(type.size()); i++)
		cout << type[i] << ' ' << res[i].first << ' ' << res[i].second << endl;
}