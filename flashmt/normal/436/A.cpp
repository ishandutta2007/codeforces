#include <bits/stdc++.h>
using namespace std;

int n, height[2222], mass[2222], type[2222];

int calc(int startingType, int strength)
{
	int candies = 0, status[2222] = {0}, currentType = startingType;
	while (1)
	{
		for (int i = 0; i < n; i++)
			if (height[i] <= strength && !status[i])
				status[i] = 1;
				
		int best = -1, id = -1;
		for (int i = 0; i < n; i++)
			if (status[i] == 1 && mass[i] > best && type[i] == currentType)
				best = mass[i], id = i;
		
		if (id < 0) break;
		
		candies++;
		strength += mass[id];
		status[id] = 2;
		currentType ^= 1;
	}
	
	return candies;
}

int main()
{
	ios::sync_with_stdio(0);
	
	int strength;
	cin >> n >> strength;
	for (int i = 0; i < n; i++) 
		cin >> type[i] >> height[i] >> mass[i];
		
	cout << max(calc(0, strength), calc(1, strength)) << endl;
}