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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 0x3f3f3f3f;
string  s1 = "144";
string s2 = "14";
string s3 = "1";
int main()
{
//	freopen("input.txt","r",stdin);
	string str;
	cin >> str;
	int i = 0;
	int l = str.length();
	int flag = 1;
	while(i < l)
	{
		string s = str.substr(i,3);
		if(s == s1)
		{
			i += 3;
			continue;
		}
		s = str.substr(i,2);
		if(s == s2)
		{
			i += 2;
			continue;
		}
		if(str[i] == s3[0])
		{
			i++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if(flag) 
		cout << "YES" <<endl;
	else
		cout << "NO" << endl;
	
	return 0;

}