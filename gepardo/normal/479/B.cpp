#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int n, m; cin >> n >> m;
	vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector < pair<int,int> > ans;
	
	for (int k = 0; k < m; k++)
	{
		int mv = 0, xv = 0;
		for (int i = 1; i < n; i++)
		{
			if (v[i] > v[xv]) xv = i;
			if (v[i] < v[mv]) mv = i; 	
		}
		if (v[xv] - v[mv] <= 1) break;

		v[xv]--, v[mv]++;
		ans.push_back(make_pair(xv + 1, mv + 1));
	}

	int mv = 0, xv = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] > v[xv]) xv = i;
		if (v[i] < v[mv]) mv = i; 	
	}
	
	cout << v[xv] - v[mv] << " " << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;

}