#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
//ifstream cin("aa.txt");
vector<int> iv;
void init(int n)
{
	iv.resize(n);
	for(int i = 0; i < n; i++)
		cin >> iv[i];
}

void opt(int n)
{
	int ans = 0;
	int min;
	bool flag = false;
	while(1)
	{
		min = 2000;
		for(int i = 0; i < n; i++)
		{
			if(min > iv[i] && iv[i] > 0)
				min = iv[i];
		}
		iv[0] -= min;
		ans += min;
		for(int i = 1; i < n; i++)
		{
			if(iv[i] >= min)
				iv[i] -= min;
			if(iv[i] == iv[i-1] && iv[i] == 0)
			{
				flag = true;
				break;
			}
		}
		if(iv[0] == 0 || iv[n-1] == 0)
		{
			flag = true;
			break;
		}
		if(flag) break;
	}
	cout << ans << endl;
}

int main()
{
	int n;
	cin >> n;
	init(n);
	opt(n);
}