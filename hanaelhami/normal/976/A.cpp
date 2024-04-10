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

	int n;
	string s;
	cin >> n >> s;

	if(s == "0")
		return cout << 0 << endl , 0;

	cout << 1;
	for(int i = 0; i < n; i++)
		if(s[i] == '0')
			cout << 0;
	cout << endl;

}