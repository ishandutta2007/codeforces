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
ifstream fin("ab.txt");
#define MEM(x) (memset((x),0,sizeof((x))))
#define MIN(x,y) ((x)<(y)?(x):(y))
vector<int> v(26);


int main()
{
	int n;
	string str;
	cin >> n >> str;
	string ans;
	for(int i = 0; i < str.length();i++)
	{
		v[str[i]-'a']++;
	}
	bool flag = true;
	for(int i = 0; i < 26; i++)
	{
		if(v[i]%n != 0)
		{
			flag = false;
			break;
		}
		for(int j = 0; j < v[i]/n; j++)
		{
			ans.push_back(char(i+'a'));
		}
	}
	if(flag)
	{
		for(int i = 0; i < n; i++)
			cout << ans;
	}
	else cout << -1;
	cout << endl;
	return 0;
}