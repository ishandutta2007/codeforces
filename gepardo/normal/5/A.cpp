#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string s;
	int cnt = 0;
	int ans = 0;
	while (true)
	{
		string s;
		getline(cin, s);	
		if (s == "") break;
		if (s[0] == '+') cnt++;
			else if (s[0] == '-') cnt--;
				else
				{
					for (int i = 0; i < s.length(); i++)
					{
						if (s[i] == ':') ans += cnt * (s.length() - i - 1);
					}
				}
		}
	cout << ans << endl;

}