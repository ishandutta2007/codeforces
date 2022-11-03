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
int flag[30];
int main()
{
	int cnt = 0;
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++)
	{
		if(flag[str[i]-'a'] == 0)
		{
			cnt ++;
			flag[str[i]-'a'] = 1;
		}
	}
	if(cnt % 2 == 1) cout << "IGNORE HIM!" << endl;
	else cout << "CHAT WITH HER!" << endl;




	return 0;
}