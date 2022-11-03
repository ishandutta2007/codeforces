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
int a[101][101];
int b[101];
int main()
{
	/*
	int n;
	cin >> n;
	MEM(b,0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(i != j)
			{
				b[i] |= a[i][j];
			}
		}
		
	
	}
	cout << b[0];
	for(int i = 1; i < n; i++)
	{
		cout << ' ' << b[i];
	}
	cout << endl;
	return 0;
}
	
	*/
	string str;
	getline(cin,str);
	string http = "http";
	string ftp = "ftp";
	string ru = "ru";
	int a,b,c;
	a = str.find(http);
	b = str.find(ftp);
	
	int i;
	if(a == -1) a= 1<<30;
	if(b==-1) b=1<<30;
	if(a < b)
	{
		i = a+4;
		cout << http;
	}
	else
	{
		i = b+3;
		cout << ftp;
	}
	cout << "://";
	for(int j = i+1 ; j < str.length(); j++)
	{
		if(str[j] == 'r' && str[j+1] == 'u')
		{
			c = j;
			break;
		}
	}
	for( ;i < c; i++)
	{
		cout << str[i];
	}

	cout << '.' << ru;
	if(c + 2 < str.length())
	{
		cout << '/';
		for(i = c+2; i < str.length(); i++)
		{
			cout << str[i];
		}
	}
	cout << endl;

	return 0;
}