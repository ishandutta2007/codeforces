#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e7 + 20;

int sum[maxn] , a[maxn];

int main()
{
	int res = 0;
	for(int i = 0; i < maxn; i++)
	{
		sum[i] = sum[i / 10] + (i % 10);
		if(sum[i] == 10)
			a[res++] = i;
	}
	int k;
	cin >> k;
	cout << a[k - 1] << endl;
}