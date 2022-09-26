#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

const int MAXN = 100005;

int n,k;
int a[MAXN];

vector<int> ans;

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i],a[i] %= k;
	int G = a[1];
	for (int i = 2;i <= n;i++)
		G = gcd(G,a[i]);
	G = gcd(G,k);
	for (int i = 0;i < k;i++)
		if (i % G == 0)
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}