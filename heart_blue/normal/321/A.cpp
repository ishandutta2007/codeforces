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
const int N =200;
const long long INF = 1<<30;
int x[2][N];
int y[2][N];
int dxy[200][2];
int main()
{
	dxy['R'][0] = 0;
	dxy['R'][1] = 1;
	dxy['L'][0] = 0;
	dxy['L'][1] = -1;
	dxy['U'][0] = 1;
	dxy['U'][1] = 0;
	dxy['D'][0] = -1;
	dxy['D'][1] = 0;
	long long a,b;
	cin >> b >> a;
	string str;
	cin >> str;
	if(a == 0 && b == 0)
	{
		cout << "Yes" << endl;
		return 0;
	}
	MEM(x,0);
	MEM(y,0);
	int l = str.length();
	for(int i = 0; i < l; i++)
	{
		x[0][i+1] = x[0][i]+dxy[str[i]][0];
		y[0][i+1] = y[0][i]+dxy[str[i]][1];
	}
	x[1][0] = x[0][l];
	y[1][0] = y[0][l];
	for(int i = 0; i < l; i++)
	{
		x[1][i+1] = x[1][i]+dxy[str[i]][0];
		y[1][i+1] = y[1][i]+dxy[str[i]][1];
	}
	for(int i = 1; i <= l; i++)
	{
		if(x[0][i] == a && y[0][i] == b)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	long long ans = INF*INF;
	for(int i = 1; i <= l; i++)
	{
		int da = x[1][i] - x[0][i];
		int db = y[1][i] - y[0][i];
		if(da == 0 && db == 0)
		{
			continue;
		}
		if(da == 0)
		{
			if(a == x[0][i] && (b-y[0][i]) % db == 0 && (b-y[0][i]) / db > 0)
				ans = min(ans,i + ((b-y[0][i])/db)*l);
			continue;
		}
		if(db == 0)
		{
			if(b == y[0][i] && (a-x[0][i])%da == 0 && (a-x[0][i])/da > 0)
				ans = min(ans,i + (a-x[0][i])/da*l);
			continue;
		}
		if((b-y[0][i]) % db == 0 && (a-x[0][i])%da == 0)
		{
			if((b-y[0][i]) / db == (a-x[0][i])/da && (a-x[0][i])/da > 0)
			{
				ans = min(ans,i+(b-y[0][i]) / db *l);
			}
		}
	}
	if(ans < INF*INF)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;



	return 0;
}