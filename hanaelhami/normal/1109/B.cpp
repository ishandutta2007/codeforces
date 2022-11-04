#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();

	int tmp = 1;
	while(tmp < n && s[tmp] == s[tmp - 1])
		tmp++;

	if(tmp >= n / 2)
		return cout << "Impossible" << endl , 0;

	for(int i = 0; i < n; i++)
	{
		string l = s.substr(0 , i + 1) , r = s.substr(i + 1);
		string res = r + l;
		if(res == s)
			continue;
		string x = r + l;
		reverse(res.begin() , res.end());

		if(res == x)
			return cout << 1 << endl , 0;
	}
	cout << 2 << endl;
}