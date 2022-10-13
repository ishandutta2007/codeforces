#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct task
{
	int time, priority, page, id;
	task() {}
	task(int _time, int _priority, int _page, int _id)
	{
		time = _time; priority = _priority; 
		page = _page; id = _id;
	}
	
	bool operator < (task u) const
	{
		if (time != u.time) return time < u.time;
		return priority > u.priority;
	}
} a[50500];

int n, missing, pageRest[50500];
long long endTime[50500], T;
set <int> setP;
vector <int> possible;

void doit(int missedPriority)
{
	priority_queue < pair<int,int> > q;
	
	for (int i = 0; i < n; i++) pageRest[i] = a[i].page;
	a[missing].priority = missedPriority;
	
	for (int i = 0; i < n; i++)
	{
		int curTime = (i?a[i - 1].time:0);

		while (!q.empty() && curTime < a[i].time)
		{
			int x = q.top().second, used = min(a[i].time - curTime, pageRest[x]);
			pageRest[x] -= used; 
			curTime += used;
			if (!pageRest[x]) endTime[a[x].id] = curTime, q.pop();
		}
		
		q.push(make_pair(a[i].priority, i));
	}
	
	long long curTime = a[n - 1].time;
	while (!q.empty())
	{
		int x = q.top().second; q.pop();
		curTime += pageRest[x];
		endTime[a[x].id] = curTime;
	}
}

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int t, p, s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> s >> p;
		a[i] = task(t, p, s, i);
		setP.insert(p);
	}
	
	cin >> T;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		if (a[i].priority < 0) missing = i;
		else
		{
			if (a[i].priority > 1 && !setP.count(a[i].priority - 1)) 
				possible.push_back(a[i].priority - 1);
			if (a[i].priority + 1 < 1000000000 && !setP.count(a[i].priority + 1))
				possible.push_back(a[i].priority + 1);
		}
	sort(possible.begin(), possible.end());
	possible.resize(unique(possible.begin(), possible.end()) - possible.begin());
	
	int low = 0, high = possible.size() - 1, ans = -1;
	while (low <= high)
	{
		int mid = (low + high)/2;
		doit(possible[mid]);
		if (endTime[a[missing].id] == T) 
		{
			ans = possible[mid]; break;
		}
		if (endTime[a[missing].id] > T) low = mid + 1;
		else high = mid - 1;
	}
	
	a[missing].priority = ans;
	cout << a[missing].priority << endl; 	
	for (int i = 0; i < n; i++) cout << endTime[i] << ' ';
}