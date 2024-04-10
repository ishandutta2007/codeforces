#include <bits/stdc++.h>

using namespace std;

const int MX = 110;
int n;
int score[MX];
pair<int, int> sorted[MX];
pair<int, int> from[MX];
pair<int, int> to[MX];

int place(int x)
{
	for (int i = 0; i < n; i++)
	{
		sorted[i] = make_pair(score[i], i);
	}
	sort(sorted, sorted + n);
	for (int i = 0; i < n; i++)
	{
		if (sorted[i].second == x)
		{
			return i;
		}
	}
	assert(false);
}

int main()
{
	cin >> n;
	vector<int> inc, dec;
	for (int i = 0; i < n; i++)
	{
		int a, d;
		cin >> a >> d;
		from[i] = {-a, i};
		to[i] = {-a - d, i};
		score[i] = from[i].first;
		if (from[i] < to[i])
		{
			inc.push_back(i);
		}
		else
		{
			dec.push_back(i);
		}
	}
	sort(inc.begin(), inc.end(), [&](int a, int b) { return from[a] < from[b]; });
	sort(dec.begin(), dec.end(), [&](int a, int b) { return from[a] > from[b]; });

	vector<int> order;
	order.insert(order.end(), inc.begin(), inc.end());
	order.insert(order.end(), dec.begin(), dec.end());

	int tot = 0;
	for (int x : order)
	{
		int a = place(x);
		score[x] = to[x].first;
		int b = place(x);
		tot += abs(a - b);
	}
	cout << tot << endl;
}