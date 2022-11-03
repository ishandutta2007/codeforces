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
const int M = 1e5;
int a[M+2];
int b[M+2];
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i] != a[i-1])
			t++;
	}
	for(int i = 1; i <= k; i++)
		b[i] = t;
	int s = a[0];
	int f = -1;
	int ans = 0;
	int key = a[0];
	f = b[a[0]];
	vector<int> v;
	v.push_back(-1);
	v.push_back(a[0]);
	for(int i = 1; i < n; i++)
	{
		if(a[i] != v[v.size()-1])
		{
			v.push_back(a[i]);
		}
	}
	v.push_back(-1);
	for(int i = 1; i < v.size()-1; i++)
	{
		b[v[i]]--;
		if(v[i-1] == v[i+1])
			b[v[i]]--;
	}
	ans = b[a[0]];
	for(int i = 1; i < v.size()-1; i++)
	{
		if(ans > b[v[i]])
		{
			ans = b[v[i]];
			key = v[i];
		}
		if(ans == b[v[i]])
		{
			key = MIN(key,v[i]);
		}
	}
	cout << key << endl;
	return 0;
}