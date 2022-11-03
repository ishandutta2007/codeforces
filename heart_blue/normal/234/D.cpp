
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
map<int,int> mp;
int u[101];
int l[101];
int main()
{
	int m,k;
	mp.clear();
	fin >> m >> k;
	int a;
	
	for(int i = 0; i < k; i++)
	{
		fin >> a;
		mp[a] = 1;
	}
	int n;
	int cnt;
	fin >> n;
	MEM(l,0);
	MEM(u,0);
	for(int i = 0; i < n; i++)
	{
		string str;
		fin >> str;
		fin >> cnt;
		int kk = k;
		int tt = 0;
		int ttt;
		for(int j = 0; j < cnt; j++)
		{
			fin >> a;
			if(a == 0) tt++;
			if(mp[a])
			{
				u[i]++;
				kk--;
			}
		}
		int K = m-(cnt - u[i] - tt)-k;
		if(K >= tt)
		{
			K = 0;
		}
		else 
		{
			K = MIN(tt-K,kk);
		}
		l[i] = u[i] + K;
		u[i] += MIN(kk,tt);
	}
	int f0,f1,f2;
	for(int i = 0; i < n; i++)
	{
		f0 = 1;
		f1 = 1;
		for(int j = 0; j < n; j++)
		{
			if(j == i) continue;
			if(u[i] < l[j])
				f0 = 0;
			if(l[i] < u[j])
				f1 = 0;


		}
		if(f0 == 1)
		{
			if(f1 == 1)
				fout << 0 << endl;
			else
				fout << 2 << endl;
		}
		else
		{
			fout << 1 << endl;
		}


	}

	return 0;
}