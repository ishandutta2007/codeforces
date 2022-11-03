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
//#include "BigNum.h"
using namespace std;
ifstream fin("aa.txt");

int main()
{
	int n;
	int m;
	vector<int> v1,v2;
	cin >> n;
	v1.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	sort(v1.begin(),v1.end());
	cin >> m;
	v2.resize(m);
	for(int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}
	int ans = 0;
	int count = 0;
	for(int i = m-1; i >= 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			if(v2[i]%v1[j]== 0)
			{
				if(ans == v2[i]/v1[j])
					count ++;
				if(ans < v2[i]/v1[j])
				{
					ans = v2[i]/v1[j];
					count = 1;
				}

				break;
			}
		}
	}
	cout << count << endl;
	return 0;
}