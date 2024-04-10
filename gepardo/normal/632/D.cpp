/*-------------------( alex256 )--------------------\
|    Contest: Educational Codeforces Round 9        |
|       Task: D                                     |
|       Date: 01. 03. 2016                          |
\--------------------------------------------------*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

const int maxN = (int)1e6 + 5;

main()
{
	int n, m; scanf("%d%d", &n, &m);   
	vector <int> q(maxN);
	vector < vector<int> > w(maxN);
	for (int i = 0; i < n; i++) 
	{
		int r; scanf("%d", &r);
		if (r >= maxN) continue;
		q[r]++;
		w[r].pb(i + 1);
	}
	vector < vector<int> > d(maxN);
	for (int i = 1; i <= maxN; i++) d[i].reserve(40);
	for (int i = 1; i <= maxN; i++)
		for (int j = i; j <= maxN; j += i)
			if (q[i] != 0) d[j].pb(i);
	int bestV = -1, bestVi;
	for (int i = 1; i <= m; i++)
	{
		int curV = 0;
		for (int j = 0; j < d[i].size(); j++) curV += q[d[i][j]];
		if (curV > bestV) bestV = curV, bestVi = i;
	}	
	printf("%d %d\n", bestVi, bestV);
	vector <int> ans;
	ans.reserve(1000001);
	int i = bestVi;
	for (int j = 0; j < d[i].size(); j++)
		for (int k = 0; k < q[d[i][j]]; k++)
			ans.pb(w[d[i][j]][k]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	return 0;
}