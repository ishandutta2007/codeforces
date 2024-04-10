#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,n,i,j,k;
int a[105];

ll S;

ll ask(int l,int r)
{
	cout << "? " << l << ' ' << r << endl;
	cout.flush();
	ll res;
	cin >> res;
	return res;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		S = ask(1,n);
		int low = 1,high = n;
		while (low < high)
		{
			int mid = low + high >> 1;
			if (ask(mid + 1,n) == S)
				low = mid + 1;
			else
				high = mid;
		}
		ll I = low,T;
		ll J = I + S - (T = ask(low + 1,n)) + 1;
		ll K = J + ask(J,n) - ask(J + 1,n);
		cout << "! " << I << ' ' << J << ' ' << K << endl;
		cout.flush();
	}
	return 0;
}