#include <cstdlib>    
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
ifstream fin("aa.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))

int main()
{
	string str;
	int n;
	cin >> n;
	while(n--)
	{
		int k = 0;
		cin >> str;
		vector<string> ans;
		int t = -1;
		string tmp;
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == ':' && str[i+1] == ':')
			{
				
				if(tmp != "")
				{
					k++;
					ans.push_back(tmp);
					tmp = "";
				}

				t = k;
				i++;
				continue;
			}
			if(str[i] == ':')
			{
				k++;
				ans.push_back(tmp);
				tmp = "";
				continue;
			}
			tmp = tmp + str[i];
			if(i == str.length()-1)
			{
				ans.push_back(tmp);
				k++;
			}
		}
		for(int i = 0; i < ans.size(); i++)
		{
			int s = ans[i].length();
			for(int j = 4; j > s; j--)
			{
				ans[i] = '0' + ans[i];
			}
		}
		int f = 0;
		for(int i = 0; i <= ans.size(); i++)
		{
			if(i == t)
			{
				int x = 1;
				while(x <= 8-k)
				{
					x++;
					if(t)
						cout << ':';
					t++;
					cout << "0000";
				}
				t = -1;
				f = 1;
			}
			if(i == ans.size())
				break;
			if(i || f)
				cout << ':';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}