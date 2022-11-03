#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

class laptop
{
public:
	int a;
	int b;
	int c;
	int d;
	bool flag;
	void init()
	{
		cin >> a >> b >> c >> d;
		flag = true;
	}
};
bool cmp(laptop l1, laptop l2)
{
	return (l1.a < l2.a && l1.b < l2.b && l1.c < l2.c);
}
vector<laptop> lvec;
int main()
{
	laptop l;
	int n;
	cin >> n;
	lvec.resize(n);
	for(int i = 0; i < n; i++)
	{
		lvec[i].init();
	}
	for(int i = 0; i < n; i++)
	{
		if(!lvec[i].flag) continue;
		for(int j = i+1; j < n; j++)
		{
			if(lvec[i].flag)
			{
				if(cmp(lvec[i],lvec[j]))
				{
					lvec[i].flag = false;
					break;
				}
				else if(cmp(lvec[j],lvec[i]))
				{
					lvec[j].flag = false;
				}
			}
		}
	}
	int min = 1000;
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(lvec[i].flag)
		{
			if(lvec[i].d <= min)
			{
				min = lvec[i].d;
				index = i;
			}
		}
	}
	cout << index+1 << endl;
	return 0;
}