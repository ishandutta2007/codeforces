#include <bits/stdc++.h>
using namespace std;

int fWash[1111], fDry[1111], fFold[1111];
set < pair<int,int> > sWash, sDry, sFold;

int main()
{
	ios::sync_with_stdio(0);
	int k, n1, n2, n3, t1, t2, t3;
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	
	for (int i = 1; i <= n1; i++) sWash.insert(make_pair(0, i));
	for (int i = 1; i <= n2; i++) sDry.insert(make_pair(0, i));
	for (int i = 1; i <= n3; i++) sFold.insert(make_pair(0, i));
	
	for (int i = 1; i <= k; i++)
	{
		int wash = sWash.begin() -> second;
		sWash.erase(sWash.begin());
		int dry = sDry.begin() -> second;
		sDry.erase(sDry.begin());
		int fold = sFold.begin() -> second;
		sFold.erase(sFold.begin());
		
		int startTime = max(fWash[wash], max(fDry[dry] - t1, fFold[fold] - t1 - t2));
		if (i == k)
		{
			cout << startTime + t1 + t2 + t3 << endl;
			return 0;
		}
		
		fWash[wash] = startTime + t1;
		sWash.insert(make_pair(fWash[wash], wash));
		fDry[dry] = startTime + t1 + t2;
		sDry.insert(make_pair(fDry[dry], dry));
		fFold[fold] = startTime + t1 + t2 + t3;
		sFold.insert(make_pair(fFold[fold], fold));
	}
}