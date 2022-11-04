#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	int n , pos , l , r;
	cin >> n >> pos >> l >> r;

	if(l == 1 && r == n)
		return cout << 0 << endl , 0;

	if(1 < l)
	{
		if(r < n)
			cout << min(abs(pos - l) + 1 + r - l + 1 , abs(pos - r) + 1 + r - l + 1) << endl;
		else
			cout << abs(pos - l) + 1 << endl;
	}
	else
		cout << abs(r - pos) + 1 << endl;
}