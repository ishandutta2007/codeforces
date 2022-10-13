#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

priority_queue < pair<int,int> > q;
vector < pair<int,int> > ans;
int a[200200];

int main()
{
	int x,s,n,step=0;
	cin >> n >> s;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x) q.push(make_pair(x,i));
	}
	while (!q.empty())
	{
		vector < pair<int,int> > processed;
		pair <int,int> u=q.top(); q.pop();
		step++;
		for (int i=0;i<u.first;i++)
		{
			if (q.empty())
			{
				puts("No");
				return 0;
			}
			pair <int,int> v=q.top(); q.pop();
			v.first--;
			ans.push_back(make_pair(u.second,v.second));
			if (v.first) processed.push_back(v);
		}
		for (int i=0;i<int(processed.size());i++) q.push(processed[i]);
	}	
	cout << "Yes" << endl << s/2 << endl;
	for (int i=0;i<int(ans.size());i++) cout << ans[i].first << ' ' << ans[i].second << endl;
}