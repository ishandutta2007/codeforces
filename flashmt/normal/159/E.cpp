#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map <int,int> d;
vector < pair<int,int> > a[100100];
priority_queue < pair<long long,int> > q;
int m,id[100100],cur[100100],rx,ry;
long long ans;

bool cmp(int x,int y)
{
	return a[x].size()>a[y].size();
}

int main()
{
	int n,c,h;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> c >> h;
		if (!d.count(c)) d[c]=++m;
		a[d[c]].push_back(make_pair(-h,i));
	}
		
	for (int i=1;i<=m;i++) id[i]=i, sort(a[i].begin(),a[i].end());
	sort(id+1,id+m+1,cmp);
	
	for (int ii=1;ii<=m;ii++)
	{
		int i=id[ii];
		long long sum=0;
		for (int j=0;j<int(a[i].size());j++) sum-=a[i][j].first;
		cur[i]=a[i].size();
		
		while (!q.empty())
		{
			pair <long long,int> u=q.top(); 
			int j=u.second;
			long long s=u.first;
			if (cur[j]>cur[i]+1)
			{
				q.pop();
				s+=a[j][--cur[j]].first;
				q.push(make_pair(s,j));
				continue;
			}
			if (s+sum>ans) ans=s+sum, rx=i, ry=j;
			break;
		}
		
		q.push(make_pair(sum,i));
	}
	cout << ans << endl << a[rx].size()+min(a[ry].size(),a[rx].size()+1) << endl;
	for (int i=0;i<int(a[rx].size());i++)
		cout << a[ry][i].second << ' ' << a[rx][i].second << ' ';
	if (a[ry].size()>a[rx].size()) cout << a[ry][a[rx].size()].second;
}