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
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
vector<int> v;
int main()
{
	int n,k;
	cin >> n >> k;
	v.resize(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int flag = 1;
	for(int i = k+1; i <= n; i++)
	{
		if(v[i] != v[i-1])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		for(k = k-1; k >= 1; k--)
		{
			if(v[k] != v[k+1])
				break;
		}
		cout << k << endl;
	}
	else cout << -1 << endl;
	return 0;
}