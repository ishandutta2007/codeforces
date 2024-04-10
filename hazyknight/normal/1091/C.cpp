#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

long long n;

vector<long long> ans;

int main()
{
	cin >> n;
	for (long long i = 1;i * i <= n;i++)
		if (n % i == 0)
		{
			ans.push_back((n + 2 - i) * (n / i) / 2);
			if (i != n / i)
				ans.push_back((n + 2 - (n / i)) * (n / (n / i)) / 2);
		}
	sort(ans.begin(),ans.end());
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}