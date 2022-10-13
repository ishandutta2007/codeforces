#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
	int n, k, a[222];
	vector < pair<int,int> > sortedValues;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
		sortedValues.push_back(make_pair(a[i], i));
	}
	
	sort(sortedValues.begin(), sortedValues.end());
	reverse(sortedValues.begin(), sortedValues.end());
	
	int ans = -oo;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		vector <int> values;
		for (int j = i; j < n; j++)
		{
			values.push_back(a[j]);
			sum += a[j];
			
			sort(values.begin(), values.end());
			int optimalSum = sum;
			for (int swap = 0, p = 0, q = 0; swap < k && p < int(values.size()); swap++)
			{
				while (q < n)
				{
					int id = sortedValues[q].second;
					if (id < i || id > j) break;
					q++;
				}
				
				if (q == n) break;
				
				if (sortedValues[q].first - values[p] >= 0)
					optimalSum += sortedValues[q].first - values[p];
				
				q++;
				p++;
			}
			
			ans = max(ans, optimalSum);
		}
	}
		
	cout << ans << endl;
}