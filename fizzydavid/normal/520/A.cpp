#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool f[30];
int main()
{
	cin >> n >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if('a' <= s[i] && s[i] <= 'z')f[s[i] - 'a']=1;
		else f[s[i]-'A']=1;
	}
	bool ok = 1;
	for(int i = 0; i < 26; i++)ok &= f[i];
	if(ok)cout << "YES" << endl;
	else cout << "NO" << endl;
}