#include <iostream>
#include <string>

using namespace std;
string deero(string test)
{
	int i;
	string ans;
	for(i = 0; i < test.length(); i++)
	{
		if(test[i] != '0')
		{
			break;
		}
	}
	if(test[i] == '.') ans = "0";
	for(int k = i; k < test.length(); k++)
	{
		ans += test[k];
	}
	return ans;


}

int main()
{
	string str;
	while(cin >> str)
	{
		int flag = 0;
		str = deero(str);
		int i = str.find_first_of(".");
		if(str[i-1] == '9')
		{
			cout << "GOTO Vasilisa." << endl;
			continue;
		}
		if(str[i+1] >= '5')
		{
			str[i-1] = char(str[i-1] + 1);
		}
		for(int k = 0; k < i; k++)
		{
			cout << str[k];
		}
		cout << endl;
	}
	return 0;
}