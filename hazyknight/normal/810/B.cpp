#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Day
{
	long long k,l;
	bool operator < (const Day & p)const
	{
		return min(k << 1,l) - min(k,l) > min(p.k << 1,p.l) - min(p.k,p.l); 
	}
}day[100005];

int n,f;
long long ans;

int main()
{
	cin >> n >> f;
	for (int i = 1;i <= n;i++)
		cin >> day[i].k >> day[i].l;
	sort(day + 1,day + n + 1);
	for (int i = 1;i <= f;i++)
		ans += min(day[i].k << 1,day[i].l);
	for (int i = f + 1;i <= n;i++)
		ans += min(day[i].k,day[i].l);
	cout << ans << endl;
	return 0;
}