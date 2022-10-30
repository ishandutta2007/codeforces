#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<long long>s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int q;
	cin >> q;
	vector<long long> que(q);
	for (int i = 0; i < q; i++)
	{
		long long x, y;
		cin >> x >> y;
		que[i]=(y - x);
	}
	sort(s.begin(), s.end());
	vector<long long>diff(n);
	for (int i = 0; i < n - 1; i++)
	{
		diff[i] = s[i + 1] - s[i];
	}
	diff[n - 1] = 1000000000000000007;
	sort(diff.begin(), diff.end());
	vector<long long>pfxs(n);
//	cout << diff[0] << ' ' << diff[1] << endl;
	pfxs[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		pfxs[i + 1] = pfxs[i] + diff[i];
	//	cout << i << ' ' << pfxs[i+1] << endl;
	}
	//cout <<"aaaa"<<' '<< diff[1] << ' ' << que[1] << endl;
//	cout << que.size() << endl;
	for (int qu = 0; qu < que.size(); qu++)
	{
		long long bv = que[qu];
		int lb = 0, rb = n - 1;
		for (int i = 0; i < 50; i++)
		{
			if (rb >= lb)
			{
				int mid = (lb + rb + i % 2)/2;
				if (diff[mid] <= bv)
				{
					lb = mid;
				}
				else
				{
					rb = mid - 1;
				}
			}
		}
		int pos = lb;
		if (diff[pos] > bv)
		{
			pos--;
		}
		if (qu == 1)
		{
		//	cout << pos << ' ' << pfxs[pos + 1] << endl;
		}
		long long ans = pfxs[pos + 1] + (bv+1) * (n - pos-1);
		cout << ans << ' ';
	}
//	cin >> n;
}