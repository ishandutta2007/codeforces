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
const  int INF = 0x7fffffff;

vector<long long> v;

int main()
{
	long long n,k;
	//cin.rdbuf(fin.rdbuf());
	cin >> n >> k;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int ans1 = 1;
	int ans2 = v[0];
	int s = 0;
	int cnt = 1;
	for(long long i = 1; i < n; i++)
	{
		if(k >= (v[i] - v[i-1])*(i-s))
		{
			k -= (v[i] - v[i-1])*(i-s);
			cnt ++;
			if(cnt > ans1)
			{
				ans1 = cnt;
				ans2 = v[i];
			}
		}
		else
		{
			while(k < (v[i]-v[i-1])*(i-s))
			{
				k += v[i-1] - v[s];
				s++;
			}
			k -= (v[i]-v[i-1])*(i-s);
			cnt = i-s+1;
			if(cnt > ans1)
			{
				ans1 = cnt;
				ans2 = v[i];
			}
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}