#include <bits/stdc++.h>
using namespace std;

int n, a[200100], f[200100], d[200100], isValid[200100];

int canCover(int d, int last, int id)
{
	return a[last] + 1LL * d * (id - last) > 0;
}

int main()
{
	ios::sync_with_stdio(0);
	//freopen("d.in", "r", stdin);
	
	while (cin >> n) 
	{
		for (int i = 1, last = 0; i <= n; i++) 
		{
			cin >> a[i];
			isValid[i] = 1;
			
			if (a[i] > 0 && last)
			{
				d[i] = (a[i] - a[last]) / (i - last);
				if (d[i] * (i - last) != a[i] - a[last]) isValid[i] = 0;
			}
			
			if (a[i] > 0) last = i;
		}
		
		int st[200100], head = 1, tail = 0;
		set < pair<int,int> > s;
		s.insert(make_pair(0, 0));
		
		for (int i = 1, bound = 0; i <= n; i++)
		{
			if (a[i] >= 0)
			{
				if (isValid[i])
					while (head < tail && d[st[head + 1]] != d[i]) bound = st[head++];
				else
				{
					bound = st[tail];
					head = tail + 1;
				}
				st[++tail] = i;
			}
			else
				while (head < tail && !canCover(d[st[tail]], st[tail], i)) bound = st[head++];

			if (head < tail)
			{
				while (1)
				{
					int id = bound + 1;
					if (id == st[head]) break;
					if (a[st[head]] - 1LL * d[st[tail]] * (st[head] - id) > 0) break;
					bound++;
				}
			}
			
			// Calc F
			while (!s.empty())
			{
				set < pair<int,int> >::iterator it = s.begin();
				if (it -> second < bound) s.erase(it);
				else
				{
					f[i] = it -> first + 1;
					break;
				}
			}
			s.insert(make_pair(f[i], i));
		}
		
		cout << f[n] << endl;
	}
}