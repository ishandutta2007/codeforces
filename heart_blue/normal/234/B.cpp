
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

vector<int> v,v1,ans;
int main()
{
	int n;
	int k;
	fin >> n >> k;
	v.resize(n);
	ans.clear();

	for(int i = 0; i < n; i++)
	{
		fin >> v[i];
	}
	v1 = v;
	sort(v.begin(),v.end());
	int t = v[n-k];
	for(int i = 0; i < n; i++)
	{
		if(v1[i] >= t)
		{
			ans.push_back(i+1);
			k--;
		}
		if(k == 0) break;
	}
	fout << t << endl;
	fout << ans[0];
	for(int i = 1; i < ans.size(); i++)
		fout << ' ' << ans[i];
	fout << endl;
	return 0;
}