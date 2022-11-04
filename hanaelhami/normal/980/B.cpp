#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;

char ch[maxn][4];

int main()
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < maxn; j++)
			ch[j][i] = '.';

	int n , k;
	cin >> n >> k;

	if(k % 2)
	{
		ch[n / 2][1] = '#';
		k--;
	}

	for(int i = 1; i < n / 2 && k >= 2; i++ , k -= 2)
		ch[i][1] = ch[n - i - 1][1] = '#';

	for(int i = 1; i < n / 2 && k >= 2; i++ , k -= 2)
		ch[i][2] = ch[n - i - 1][2] = '#';

	if(k > 0)
		ch[n / 2][1] = ch[n / 2][2] = '#';

	cout << "YES" << endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < n; j++)
			cout << ch[j][i];
		cout << endl;
	}
		
}