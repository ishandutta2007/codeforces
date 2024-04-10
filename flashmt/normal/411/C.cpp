#include <bits/stdc++.h>
using namespace std;

int attack[4], defence[4];

int result(int x, int y, int z, int t)
{
	if (attack[x] > defence[t] && defence[y] > attack[z]) return 1;
	if (attack[x] < defence[t] && defence[y] < attack[z]) return 2;
	return 4;
}

int main()
{
	for (int i = 0; i < 4; i++) cin >> attack[i] >> defence[i];
	
	int mask1 = result(0, 1, 2, 3) | result(0, 1, 3, 2);
	int mask2 = result(1, 0, 2, 3) | result(1, 0, 3, 2);
	
	if (mask1 == 1 || mask2 == 1) cout << "Team 1\n";
	else if ((mask1 & mask2) >> 1 & 1) cout << "Team 2\n";
	else cout << "Draw\n";
}