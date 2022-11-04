#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int x = 0 , n = s.size();

	for(int i = 0; i < n; i++)
		if(s[i] == '-')
			x++;

	int y = n - x;

	if(!y || x % y == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}