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
ifstream fin("ab.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
char a[51][51];
char b[51][51];
int main()
{
	int x = 0;
	int y = 0;
	int na,ma;
	int nb,mb;
	cin >> na >> ma;
	for(int i = 1; i <= na; i++)
	{
		for(int j = 1; j <= ma; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> nb >> mb;
	for(int i = 1; i <= nb; i++)
	{
		for(int j = 1; j <= mb; j++)
		{
			cin >> b[i][j];
		}
	}
	int sum = 0;
	int ansx = -1;
	int ansy = -1;
	int ans = -1;
	bool flag;
	for(x = -50; x <= 51; x++)
	{
		for(int y = -50; y <= 51; y++)
		{
			sum = 0;
			flag = false;
			for(int i = 1; i <= na; i++)
			{
				if(i + x > nb) break;
				if(i + x < 1) continue;
				for(int j = 1; j <= ma; j++)
				{
					if(j + y > mb) break;
					if(j + y < 1) continue;
					flag = true;
					sum += (a[i][j]-'0')*(b[i+x][j+y]-'0');
				}
			}
			if(sum > ans && flag)
			{
				ans = sum;
				ansx = x;
				ansy = y;
			}
		}
	}
	cout << ansx << ' ' << ansy << endl;
	return 0;
}