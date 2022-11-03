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

map<int,int> mi;
map<int,int> mi2;
map<int,string> ms;
int a[51];
string tostr(int n)
{
	string str;
	while(n)
	{
		str = char('0'+(n%10))+str;
		n/=10;
	}
	str = ' ' + str;
	return str;
}
vector<int> v1,v2;
int main()
{
	int n;
	int k;
	cin >> n >> k;
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		
	}
	map<int,int>::iterator it;
	mi[0] = 1;
	if(t < k)
	{
		for(int i = 0; i < n; i++)
		{
			v1.clear();
			v2.clear();
			for(it = mi.begin(); it != mi.end(); it++)
			{
				int l = (*it).first;
				
				int r = (*it).second;
				if(r == 0) continue;
				if(mi2[l+a[i]] == 0)
				{
					v1.push_back(l+a[i]);
					v2.push_back(r+1);
					ms[l+a[i]] = ms[l] + tostr(a[i]);
					t++;
					if(t==k) break;
				}
			}
			for(int j = 0; j < v1.size(); j++)
			{
				mi[v1[j]] = v2[j];
			}
			if(t == k) break;
			mi2 = mi;
		}
	}
	it = mi.begin();
	it ++;
	for(; it != mi.end(); it++)
	{
		cout << (*it).second-1 << ms[(*it).first] << endl;
	}



		

	return 0;
}