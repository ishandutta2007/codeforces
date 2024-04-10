#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

pair<pair<int , int> , int> a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].first.second *= -1;
		a[i].second = i;
	}

	sort(a , a + n);

	for(int i = 0; i < n; i++)
		a[i].first.second *= -1;

	int mx = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[mx].first.second >= a[i].first.second)
			return cout << a[i].second + 1 << " " << a[mx].second + 1 << endl , 0;
		else
			mx = i;
	}

	cout << "-1 -1" << endl;
}