#include <bits/stdc++.h>
using namespace std;

int n, d, a[100100], b[100100], pos[100100], ans[100100];
long long x;

int getNextX()
{
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

void initAB() 
{
	for (int i = 0; i < n; i = i + 1) a[i] = i + 1;
	for (int i = 0; i < n; i = i + 1) swap(a[i], a[getNextX() % (i + 1)]);
	for (int i = 0; i < n; i = i + 1)
		if (i < d) b[i] = 1;
		else b[i] = 0;
	for (int i = 0; i < n; i = i + 1) swap(b[i], b[getNextX() % (i + 1)]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> d >> x;
	initAB();
	
	vector <int> idB;
	for (int i = 0; i < n; i++)
		if (b[i]) idB.push_back(i);
		
	for (int i = 0; i < n; i++) pos[a[i]] = i;
	set <int> available;
	for (int i = 0; i < n; i++) available.insert(i);
	
	for (int x = n; x; x--)
	{
		set <int>::iterator it;
		for (int i = 0; i < int(idB.size()) && idB[i] + pos[x] < n;)
		{
			int id = idB[i] + pos[x];
			it = available.lower_bound(id);
			
			if (it == available.end()) break;
			
			if (id == *it) 
			{
				ans[id] = x;
				available.erase(id);
				i++;
			}
			else
				i = lower_bound(idB.begin(), idB.end(), *it - pos[x]) - idB.begin();
		}
	}
	
	for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}