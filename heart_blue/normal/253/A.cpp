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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n >= m)
	{
		if(n == m)
		{
			for(int i = 0; i < n; i++)
			{
				cout << "BG";
			}
			cout << endl;
		}
		else
		{
			cout << "B";
			for(int i = 0; i < m; i++)
			{
				cout << "GB";
			}
			for(int i = m+1; i < n; i++)
			{
				cout << "B";
			}
			cout << endl;
		}
	}
	else
	{
		if(n == m)
		{
			for(int i = 0; i < n; i++)
			{
				cout << "GB";
			}
			cout << endl;
		}
		else
		{
			cout << "G";
			for(int i = 0; i < n; i++)
			{
				cout << "BG";
			}
			for(int i = n+1; i < m; i++)
			{
				cout << "G";
			}
			cout << endl;
		}
	}




	return 0;
}