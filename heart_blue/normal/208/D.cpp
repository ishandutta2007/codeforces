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
//#include "BigNum.h"

using namespace std;
/*
int n;
vector<string> vs;
vector<int> flag;
bool ans;
void dfs(int k)
{
	if(ans) return;
	if(k == 1)
	{
		ans = true;
		return;
	}
	for(int i = n-1; i > 0; i--)
	{
		if(!flag[i])
		{
			int key1,key2;
			key1 = key2 = -1;
			int k = 0;
			for(int j = i-1; j >= 0; j --)
			{
				if(!flag[j]) k++;
				if(k == 1) key1 = j;
				if(k == 3)
				{
					key2 = j;
					break;
				}
			}
			flag[i] = 1;
			string t;
			if(key1 >= 0)
			{
				if(vs[key1][0] == vs[i][0] || vs[key1][1] == vs[i][1])
				{
					t = vs[key1];
					vs[key1] = vs[i];
					dfs(k-1);
					vs[key1] = t;
				}
			}
			if(key2 >= 0)
			{
				if(vs[key2][0] == vs[i][0] || vs[key2][1] == vs[i][1])
				{
					t = vs[key2];
					vs[key2] = vs[i];
					dfs(k-1);
					vs[key2] = t;
				}
			}
			flag[i] = 0;
		}
		if(ans) return;
	}
}
int main()
{
	cin >> n;
	vs.resize(n);
	flag.resize(n,0);
	for(int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	ans = false;
	dfs(n);
	cout << (ans ? "YES":"NO") << endl;
	return 0;
}
		

*/
vector <long long> ch,pr,ans;
int main()
{
	int n;
	cin >> n;
	ch.resize(n);
	pr.resize(5);
	ans.resize(5,0);
	for(int i = 0; i < n; i++)
		cin >> ch[i];
	for(int i = 0; i < 5; i++)
		cin >> pr[i];
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += ch[i];
		int key;
		long long MAX;
		while(1)
		{
			key = -1;
			MAX = 0;
			for(int j = 0; j < 5; j++)
			{
				if(pr[j] > MAX && sum >= pr[j])
				{
					MAX = pr[j];
					key = j;
				}
			}
			if(key == -1) break;
			ans[key] += sum/pr[key];
			sum %= pr[key];
		}
	}
	for(int i = 0; i < 5; i++)
	{
		cout << ans[i] << (i != 4 ? ' ' : '\n');
	}
	cout << sum << endl;
	return 0;
}