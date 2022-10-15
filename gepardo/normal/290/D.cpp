#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s; cin >> s;
	string ans = "";
	int n; cin >> n;
	for (int i = 0; i < s.length(); i++) s[i] |= 32;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c < n + 97) 
			ans += char(c & (127 - 32));
		else
			ans += char(c | 32);	
	}	
	cout << ans;
}