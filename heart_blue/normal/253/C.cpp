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

int a[101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i]++;
	}
	int r1,c1,r2,c2;
	cin >> r1 >> c1 >> r2 >> c2;



int ans = 0;
	if(r1 >= r2)
	{
		int cur = c1;
		for(int i = r2; i <= r1; i++)
		{
			cur = MIN(cur,a[i]);
		}
		ans = r1-r2 + abs(cur-c2);
		int cur1,ans1,cur2,ans2;
		cur1 = cur2 = cur;
		ans1 = ans2 = ans;
		for(int i = r1; i <= n; i++)
		{
			if(a[i] < cur1)
			{
				cur1 = a[i];
				ans1 = MIN(ans1,(i-r1)*2+r1-r2+abs(cur1-c2));
			}
		}
		ans = MIN(ans,ans1);
		for(int i = r2; i > 0; i--)
		{
			if(a[i] < cur2)
			{
				cur2 = a[i];
				ans2 = MIN(ans2,r1-r2+(r2-i)*2+abs(cur2-c2));
			}
		}
		ans = MIN(ans,ans2);
	}
	else
	{
		int cur = c1;
		for(int i = r1; i <= r2; i++)
		{
			cur = MIN(cur,a[i]);
		}
		ans = r2-r1 + abs(cur-c2);
		int cur1,ans1,cur2,ans2;
		cur1 = cur2 = cur;
		ans1 = ans2 = ans;
		for(int i = r1; i > 0; i--)
		{
			if(cur1 > a[i])
			{
				cur1 = a[i];
				ans1 = MIN(ans1,(r1-i)*2+r2-r1+abs(cur1-c2));
			}
		}
		for(int i = r2; i <= n; i++)
		{
			if(cur2 > a[i])
			{
				cur2 = a[i];
				ans2 = MIN(ans2,(i-r2)*2+r2-r1+abs(cur2-c2));
			}
		}
		ans = MIN(ans,ans1);
		ans = MIN(ans,ans2);
	}
	cout  << ans << endl;



	


	return 0;
}