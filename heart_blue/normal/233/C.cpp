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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
int a[101][101];
int b[101];
int s[101];
int main()
{
	int k;
	for(int i = 3; i < 101; i++)
	{
		b[i] = i*(i-1)*(i-2)/6;
		s[i] = i*(i-1)/2;
	}
	s[2] = 1;
	cin >> k;
	int key;
	for(int i = 100; i > 0; i--)
	{
		if(k >= b[i])
		{
			key = i;
			break;
		}
	}
	int tmp = k-b[key];
	MEM(a,0);
	for(int i = 1; i <= key; i++)
	{
		for(int j = 1; j <= key; j++)
		{
			if(i != j) 
				a[i][j] = 1;
		}
	}
	int x,y,z;
	z = key;
	if(tmp != 0)
	{
		
		bool flag = false;
		for(x = 1; x <= key; x++)
		{
			for(y = 1; y <= key; y++)
			{
				for(z = 1; z <= key; z++)
				{
					if(s[x] + s[y] + s[z] == tmp)
					{
						flag = true;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag) break;
		}
		if(x == 1) x = 0;
		else key ++;
		for(int i = 1; i <= x;i++)
		{
			if(key == i) x++;
			a[key][i] = a[i][key] = 1;
		}
		if(y == 1) y = 0;
		else key++;
		for(int i = 1; i <= y; i++)
		{
			if(key == i) y++;
			a[key][i] = a[i][key] = 1;
		}
		if(z == 1) z = 0;
		else key ++;
		for(int i = 1; i <= z; i++)
		{
			if(key == i) z++;
			a[key][i] = a[i][key] = 1;
		}
	}
	cout << key << endl;
	for(int i = 1; i <= key; i++)
	{
		for(int j = 1; j <= key; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}


	return 0;
}