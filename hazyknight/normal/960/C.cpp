#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;


int x,d;
long long INF = 100000000000000000ll;

vector<long long> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> x >> d;
	long long now = 1;
	for (int i = 30;i >= 0;i--)
	{
		if (x >= (1 << i))
		{
			x -= (1 << i);
			for (int j = 1;j <= i;j++)
				ans.push_back(now);
			ans.push_back(INF);
			now += d + 1;
			INF += d + 1;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl; 
	return 0;
}