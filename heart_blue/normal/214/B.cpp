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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MEM(x) (memset((x),0,sizeof((x))))
template <class T> void change(T &a, T &b)// 
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <class T> void quicksort(vector<T> &S,int a,int b) // 
{
     int x = a;
	 int y = b;
	 T mid = S[(a+b)>>1];
     while (x <= y)
     {
           while (S[x] > mid) x++;
           while (S[y] < mid) y--;
           if (x <= y)
           {
              change(S[x], S[y]);
              x++;
              y--;
           }
     }
     if (x < b) quicksort(S, x, b);
     if (y > a) quicksort(S, a, y);
}
vector<int> v;
int main()
{
	int n;
	cin >> n;
	v.resize(n);
	int sum = 0;
	int num = 0;
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		if(v[i] == 0) flag = true;
		if(v[i] > 0) num++;
	}
	if(flag)
	{
		quicksort(v,0,n-1);
		if(sum % 3)
		{
			int t = sum%3;
			int k = -1;
			int k1,k2;
			for(int i = v.size()-1; i >= 0; i--)
			{
				if(v[i]%3 == t)
				{
					k = i;
					break;
				}
			}
			if(k == -1) 
			{
				k1 = k2 = -1;
				for(int i = v.size()-1; i >= 0; i--)
				{
					if(v[i]%3)
					{
						k1 = i;
						break;
					}
				}
				for(int i = k1-1; i >= 0; i--)
				{
					if(v[i]%3)
					{
						k2 = i;
						break;
					}
				}
				if(k1 < 0 || k2 < 0) cout << -1 << endl;
				else
				{
					if(num == 2) cout << 0 << endl;
					else
					{
						for(int i = 0; i < v.size(); i++)
						{
							if(i != k1 && i != k2)
							{
								cout << v[i];
							}
						}
						cout << endl;
					}
				}
			}
			else if(k == 0 && v[1] == 0)
			{
				cout << 0 << endl;
			}
			else
			{

				for(int i = 0; i < v.size(); i ++)
				{
					if(i != k)
					{
						cout << v[i];
					}
				}
				cout << endl;
			}
		}
		else
		{
			if(v[0] == 0) cout << 0 << endl;
			else
			{
				for(int i = 0; i < v.size(); i ++)
				{
					cout << v[i];
				}
				cout << endl;
			}
		}
	}
	else cout << -1 << endl;
	return 0;
}