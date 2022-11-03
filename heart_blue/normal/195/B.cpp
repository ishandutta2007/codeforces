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

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> v(m+1);
	if(m % 2 == 1)
	{
		v[1] = (m+1)/2;
		int t = v[1];
		int k = 2;
		int i = 1;
		if(m == 1) 
		{
			v[0] = v[1];
		}
		else
		while(1)
		{
			
			v[k] = t - i;
			v[k+1] = t + i;
			if(v[k+1] == m) 
			{
				v[0] = m;
				break;
			}
			k+= 2;
			i++;
		}
	}
	else
	{
		int t = (m+1)/2;
		int k = t+1;
		int i = 1;
		while(1)
		{
			v[i] = t;
			v[i+1] =k;
			if(k == m)
			{
				v[0] = m;
				break;
			}
			i += 2;
			t--;
			k++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << v[i%m] << endl;
	return 0;


}