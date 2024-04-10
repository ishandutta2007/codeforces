#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2e5;
int a[N], idx[N], t[N+1], ans[N];

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i)
		cin >> a[idx[i] = i];
	sort(idx, idx + n, [&](const int& x, const int& y){return a[x] < a[y];});
	priority_queue<int,vector<int>,function<bool(const int& x, const int& y)>>
		H([&](const int& x, const int& y){return t[x] > t[y];});
	for (int i = 0, day = 0; i < n; ++i)
	{
		if (!H.empty() && t[H.top()] + d < a[idx[i]])
			day = H.top(), H.pop();
		else
			day = H.size() + 1;
		t[ans[idx[i]] = day] = a[idx[i]];
		H.push(day);
	}
	cout << H.size() << endl;
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}