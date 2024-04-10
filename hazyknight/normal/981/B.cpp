#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

int n;
int x,y;

long long ans;

map<int,pair<int,int> > match;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> x >> y;
		match[x].first = y;
	}
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> x >> y;
		match[x].second = y;
	}
	for (map<int,pair<int,int> >::iterator i = match.begin();i != match.end();i++)
		ans += max((*i).second.first,(*i).second.second);
	cout << ans << endl;
	return 0;
}