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
	
		string str;
	int a,b;
	getline(cin,str);
	int t = 0;
	a = 0; 
	b = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '-')
		{
			t--;
			b = MIN(b,t);
		}
		else
		{
			t++;
			a = MAX(a,t);
		}
		
	}
	cout << a-b << endl;
	return 0;
}
	
	/*
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
	for(int j = i ; j < str.length(); j++)
	{
		if(str[i] == 'r' && str[i+1] == 'u')
		{
			c = i;
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
	/*
	int a,b;
	int t,x,y;
	int n;
	cin >> n;
	a = b = 0;
	int c = 0;
	int d = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>t >> x>>y;
		if(t == 1) a+=x,c++;
		else b+=x,d++;
	}
	if(a * 2 >= c*10)
	{
		cout << "LIVE" << endl;
	}
	else
	{
		cout <<"DEAD" << endl;
	}
	if(b*2 >=d*10)
	{
		cout << "LIVE" << endl;
	}
	else
	{
		cout << "DEAD" << endl;
	}
	return 0;
}
*/