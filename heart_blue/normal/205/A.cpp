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




int main()
{
	int n;
	cin >> n;
	int key = 0;
	int count = 0;
	long long min = 1000000000000;
	long long a;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		if(min > a)
		{
			min = a;
			key = i;
			count = 1;
		}
		else if(min == a)
		{
			count ++;
		}
	}
	if(count == 1) cout << key << endl;
	else if(count > 1) cout << "Still Rozdil\n";
	return 0;
}