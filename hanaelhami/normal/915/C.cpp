#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int t[maxn];

string res;

string f()
{
	string tmp;
	for(int i = 9; i >= 0; i--)
		for(int j = 0; j < t[i]; j++)
			tmp += (char)(i + '0');
	return tmp;
}

int main()
{
	string a , b;
	cin >> a >> b;

	if(a.size() < b.size())
	{
		sort(a.begin() , a.end());
		reverse(a.begin() , a.end());

		cout << a << endl;
		return 0;
	}

	for(int i = 0; i < (int)a.size(); i++)
		t[a[i] - '0']++;

	for(int i = 0; i < (int)b.size(); i++)
	{
		for(int j = 0; j + '0' < b[i]; j++)
		{
			if(!t[j])
				continue;
			t[j]--;
			string x = b.substr(0 , i);
			x += (char)(j + '0');
			x += f();
			if(x[0] != '0')
				res = max(res , x);
			t[j]++;
		}
		if(!t[b[i] - '0'])
		{
			cout << res << endl;
			return 0;
		}
		else
			t[b[i] - '0']--;
	}
	res = max(res , b);
	cout << res << endl;
}