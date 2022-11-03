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