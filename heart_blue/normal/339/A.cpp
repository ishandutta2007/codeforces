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
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
int a[10000];
int main()
{
	//freopen("input.txt","r",stdin);
	string str;
	getline(cin,str);
	str += '+';
	int tmp = 0;
	int k = 0;
	int l = str.length();
	for(int i = 0; i < l; i++)
	{
		if(isdigit(str[i]))
		{
			tmp = tmp*10+str[i]-'0';
		}
		else
		{
			a[k++] = tmp;
			tmp = 0;
		}
	}
	sort(a,a+k);
	cout << a[0];
	for(int i = 1; i < k; i++)
	{
		cout << '+' << a[i];
	}
	cout << endl;
	return 0;
}