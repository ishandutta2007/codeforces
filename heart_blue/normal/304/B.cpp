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
const int N = 1020;

int day[2][13] = {0,31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31};
int dis(int y1, int y2)
{
	y1 ++;
	y2 --;
	int cnt = 0;
	for(int i = y1; i <= y2; i++)
	{
		if(i%4 == 0)
		{
			if(i%100 == 0)
			{
				if(i%400 == 0)
				{
					cnt++;
				}
			}
			else
				cnt++;
		}
	}
	return cnt + (y2-y1+1)*365;
}

int isleap(int i)
{
	int cnt = 0;
	if(i%4 == 0)
		{
			if(i%100 == 0)
			{
				if(i%400 == 0)
				{
					cnt++;
				}
			}
			else
				cnt++;
		}
	return cnt;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int y1,m1,d1;
	int y2,m2,d2;
	scanf("%d:%d:%d",&y1,&m1,&d1);
	scanf("%d:%d:%d",&y2,&m2,&d2);
	if(y1 > y2)
	{
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	else if(y1 == y2)
	{
		if(m1 > m2)
		{
			swap(m1,m2);
			swap(d1,d2);
		}
		else if(m1 == m2)
		{
			if(d1 > d2)
			{
				swap(d1,d2);
			}
		}
	}

	int dist = 0;
	int ans = 0;
	if(y1 == y2)
	{
		if(m1 == m2)
		{
			ans = d2-d1;
		}
		else
		{
			int c = isleap(y1);
			for(int i = m1+1; i < m2; i++)
			{
				ans += day[c][i];
			}
			ans += day[c][m1] - d1 + d2;
		}
	}
	else
	{
		ans += dis(y1,y2);
		for(int i = m1; i <= 12; i++)
		{
			ans += day[isleap(y1)][i];
		}
		ans -= d1;
		for(int i = 1; i < m2; i++)
		{
			ans += day[isleap(y2)][i];
		}
		ans += d2;
	}
	cout << ans << endl;

}