#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn] , f[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(f , -1 , sizeof f);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
	{
		int tmp = a[i];
		while(tmp >= 0 && f[tmp] == -1 && a[i] - tmp + 1 <= k)
			tmp--;

		if(tmp >= 0 && a[i] - tmp + 1 <= k && a[i] - f[tmp] + 1 <= k)
			tmp = f[tmp];
		else
			tmp++;
		
		for(int j = tmp; j <= a[i]; j++)
			f[j] = tmp;
	}

	for(int i = 0; i < 256; i++)
		if(f[i] == -1)
			f[i] = i;

	for(int i = 0; i < n; i++)
		cout << f[a[i]] << " ";
	cout << endl;
}