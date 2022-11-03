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
class card
{
public:
	int num;
	int red;
	card()
	{
		num = 0;
		red = 0;
	}
};
	
map<int,card> M;
int main()
{
	int n;
	int a,b;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if(a != b)
		{
			M[a].num ++;
			M[b].red ++;
		}
		else
			M[a].num ++;
	}
	map<int,card>::iterator it;
	int min = n;
	bool flag = false;
	for(it = M.begin(); it != M.end(); it++)
	{
		if((*it).second.num + (*it).second.red >= int(n/2.0+0.6))
		{
			flag = true;
			int t = int(n/2.0+0.6) - (*it).second.num;
			if(t <= 0)
			{
				min = 0; 
				break;
			}
			if(t < min) min = t;
		}
	}
	if(flag)
		cout << min << endl;
	else cout << -1 << endl;
	return 0;

}