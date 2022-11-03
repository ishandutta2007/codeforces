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
const int N = 1e5;
int a[N+10];
int s1[N+10];
int s2[N+10];
int flag[N+10];
int main()
{
	int n;
	//freopen("input.txt","r",stdin);
	cin >> n;
	MEM(a,0);
	for(int i = 0; i < n; i ++) cin >> a[i];
	MEM(s1,0);
	MEM(s2,0);
	s1[0] = a[0];
	for(int i = 1; i < n; i++) s1[i] = a[i] + s1[i-1];
	char c;
	for(int i = 0; i < n; i++)
	{
		cin >> c;
		flag[i] = c - '0';
	}
	for(int i = n-1; i >= 0; i--)
	{
		s2[i] = s2[i+1];
		if(flag[i]) s2[i] += a[i];
	}
	int ans = s2[0];
	for(int i = 1; i < n; i++)
	{
		if(flag[i])
		{
			ans = max(ans,s1[i-1]+s2[i+1]);
		}
	}
	cout << ans << endl;
	
	return 0;
}