#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100;

typedef unsigned long long int in;

in pocx, pocy, ax, ay, bx, by, sx, sy, t;

in pref[maxn];

vector <pair <in, in> > svi;

int main()
{
	cin >> pocx >> pocy >> ax >> ay >> bx >> by >> sx >> sy >> t;
	pref[0] = 0;
	in sljx = pocx, sljy = pocy;
	in zadx = pocx, zady = pocy;
	int br = 0;
	svi.push_back(make_pair(pocx, pocy));
	while(1)
	{
		sljx = zadx * ax + bx;
		if(sljx > 1e17) break;
		sljy = zady * ay + by;
		if(sljy > 1e17) break;
		br++;
		pref[br] = pref[br - 1] + (sljx - zadx) + (sljy - zady);
		zadx = sljx;
		zady = sljy;
		svi.push_back(make_pair(zadx, zady));
	}
	int maxrj = 0;
	REP(i, 0, (int)svi.size())
	{
		REP(j, 0, (int)svi.size())
		{
			in tr = pref[max(i, j)] - pref[min(i, j)];
			if(svi[i].first > sx) tr += svi[i].first - sx;
			else tr += sx - svi[i].first;
			if(svi[i].second > sy) tr += svi[i].second - sy;
			else tr += sy - svi[i].second;
			if(tr <= t)
			{
				maxrj = max(maxrj, abs(i - j) + 1);
			}
		}
	}
	cout << maxrj << endl;
	return 0;
}