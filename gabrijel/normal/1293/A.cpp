#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

map <int, bool> ne;

int main()
{
	int t;
	cin >> t;
	int n, s, k;
	REP(tt, 0, t)
	{
		ne.clear();
		cin >> n >> s >> k;
		int x;
		REP(i, 0, k)
		{
			scanf("%d", &x);
			ne[x] = 1;
		}
		int br = 0;
		while(1)
		{
			if(s - br > 0)
			{
				if(!ne[s - br]) break;
			}
			if(s + br <= n)
			{
				if(!ne[s + br]) break;
			}
			br++;
		}
		cout << br << endl;
	}
	return 0;
}