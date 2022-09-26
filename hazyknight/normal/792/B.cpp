#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n,k;
int a[200005];

vector<int> v;

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		v.push_back(i);
	for (int i = 1;i <= k;i++)
		cin >> a[i];
	int pos = 0;
	for (int i = 1;i <= k;i++)
	{
		pos = (pos + a[i]) % v.size();
		cout << v[pos] << ' ';
		v.erase(v.begin() + pos);
	}
	cout << endl;
	return 0;
}