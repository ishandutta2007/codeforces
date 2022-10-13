#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s, t = "";
	vector <string> ans;
	
	getline(cin, s);
	s += ' ';
	int isOpen = 0;
	for (int i = 0; i < int(s.size()); i++)
		if (isOpen == 1)
		{
			if (s[i] == '"') ans.push_back(t), t = "", isOpen = 0;
			else t += s[i];
		}
		else
		{
			if (s[i] == '"') isOpen = 1, t = "";
			else
				if (s[i] == ' ')
				{
					if (isOpen == 2) ans.push_back(t), t = "", isOpen = 0;
				}
				else t += s[i], isOpen = 2;
		}
		
	for (int i = 0; i < int(ans.size()); i++) cout << '<' << ans[i] << '>' << endl;
}