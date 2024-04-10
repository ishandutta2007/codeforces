#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;

string s[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	int res = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			int tmp = j;
			while(tmp < m && s[i][tmp] == '.')
				tmp++;
			int L = tmp - j;
			if(L >= k)
				res += (L - k + 1);
			j = tmp;
		}
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
		{
			int tmp = i;
			while(tmp < n && s[tmp][j] == '.')
				tmp++;
			int L = tmp - i;
			if(L >= k)
				res += (L - k + 1);
			i = tmp;
		}
	if(k == 1)
		res /= 2;
	cout << res << endl;
}