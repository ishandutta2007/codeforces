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
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MEM(a,b) (memset((a),(b),sizeof(a)))


vector<int> v(100001);
int flag[100001];
int n,k;
int l,r;
int main()
{
	scanf("%d%d",&n,&k);
	MEM(flag,0);
	int cnt = 0;
	bool f = false;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
		if(f) continue;
		flag[v[i]]++;
		if(flag[v[i]] == 1)
		{
			cnt ++;
		}
		if(cnt == k)
		{
			l = 0;
			r = i;
			f = true;
		}
	}
	if(f) 
	{
		MEM(flag,0);
		for(int i = 0; i <= r; i++)
		{
			flag[v[i]]++;
		}
		for(int i = 0; i <= r; i++)
		{
			flag[v[i]]--;
			if(flag[v[i]] == 0)
			{
				l = i;
				break;
			}
		}
		cout << l+1 << ' ' << r+1 << endl;
	}
	else cout << -1 << ' ' << -1 << endl;
	return 0;
}