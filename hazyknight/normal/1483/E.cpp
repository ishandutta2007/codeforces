#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int T;
 
ll sum,M;
 
int tim = 0;
bool test(ll X)
{
	tim++;
	cout << "? " << X << endl;
	cout.flush();
	string res;
	cin >> res;
	if (res == "Fraudster!")
	{
		sum -= X;
		return 0;
	}
	sum += X;
	return 1;
}
 
void singletest()
{
	tim = 0;
//	cin >> M;
	sum = 1;
	ll low,high;
	for (ll i = 1;;i <<= 1)
	{
		if (i > 1e14)
		{
			low = (i >> 1);
			high = 1e14;
			break;
		}
		if (!test(i))
		{
			if (i == 1)
			{
				cout << "! " << 0 << endl;
				return;
			}
			low = (i >> 1);
			high = i - 1;
			break;
		}
	}
	while (low < high)
	{
		ll mid = high - (high - low) * 0.7;
		if (sum >= high * 2)
			mid = high - (high - low) * 0.6 + 1;
		if (sum >= high * 4)
			mid = high - (high - low) * 0.55 + 1;
		if (high - low + 1 == 2)
			mid = high;
		if (high - low + 1 == 3)
			mid = low + 1;
		if (sum < mid)
		{
			test(low);
			continue;
		}
		if (test(mid))
			low = mid;
		else
			high = mid - 1;
	}
	cout << "! " << low << endl;
	cout.flush();
}
 
int main()
{
	cin >> T;
	while (T--)
		singletest();
	return 0;
}