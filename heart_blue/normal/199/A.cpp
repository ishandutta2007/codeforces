#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <fstream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
vector <int> v(1000000);
int main()
{
	int n;
	cin >> n;
	if(n < 3) 
	{
		if(n == 0) cout << "0 0 0\n";
		if(n == 1) cout << "0 0 1\n";
		if(n == 2) cout << "0 1 1\n";
	}
	else
	{
		v[0] = 0; v[1] = v[2] = 1;v[3] = 2;
		for(int i = 4; i < v.size(); i++)
		{
			v[i] = v[i-1] + v[i-2];
			if(v[i] == n)
			{
				printf("%d %d %d\n",v[i-3],v[i-2],v[i-2]) ;
				break;
			}
		}
	}
	return 0;
}