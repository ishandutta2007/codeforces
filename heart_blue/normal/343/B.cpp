#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
using namespace std;
#define MAX (a,b) ((a)>(b)?(a):(b))
#define MIN (a,b) ((a)<(b)?(a):(b))
#define MEM(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
	//freopen("input.txt","r",stdin);
	string str;
	int a = 0;
	char c;
	int i =0;
	cin >> str;
	int l = str.length();
	int cnt = 0;
	while(i != l)
	{
		c = str[i++];
		if(a == 0)
		{
			a = 1;
			if(c == '-') cnt --;
			if(c == '+')
			{
				cnt ++;
			}
		}
		else
		{
			a = 0;
			if(c == '+') cnt --;
			else cnt ++;
		}
	}
	if(cnt == 0) cout << "Yes" << endl;
	else cout <<"No" << endl;
	
	return 0;
}