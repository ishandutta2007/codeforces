
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
ifstream fin("input.txt");
ofstream fout("output.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
const int M = 1e5+10;
int u[M];
int a[M];
int main()
{
	int n;
	fin >> n;
	MEM(u,0);
	for(int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	for(int i = n-2; i >= 0; i--)
	{
		if(a[i+1] <= 0)
			u[i] = u[i+1]+1;
		else
			u[i] = u[i+1];
	}
	int t = 0;
	int ans = 1<<30;
	for(int i = 0; i < n-1; i++)
	{
		if(a[i] >= 0)
			t++;
		ans = MIN(ans,t+u[i]);
	}
	fout << ans << endl;

	return 0;
}