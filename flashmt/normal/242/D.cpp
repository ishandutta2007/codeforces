#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,num[100100],cnt[100100];
vector <int> a[100100],ans;

int main()
{
	int m,x,y;
	cin >> n >> m;
	while (m--) cin >> x >> y, a[x].push_back(y), a[y].push_back(x);
	for (int i=1;i<=n;i++) cin >> num[i];
	
	queue <int> q;
	for (int i=1;i<=n;i++)
		if (num[i]==cnt[i]) q.push(i);
		
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		if (cnt[x]!=num[x]) continue;
		cnt[x]++;
		ans.push_back(x);
		for (int i=0;i<int(a[x].size());i++)
		{
			int y=a[x][i];
			if (++cnt[y]==num[y]) q.push(y);
		}
	}
	
	cout << ans.size() << endl;
	for (int i=0;i<int(ans.size());i++) cout << ans[i] << ' ';
}