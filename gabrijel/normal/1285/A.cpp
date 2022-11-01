#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int br = 0;
	REP(i, 0, (int)s.size())
	{
		if(s[i] == 'L') br++;
		else br--;
	}
	int br_vise = abs(br);
	br_vise += (n - br_vise) / 2;
	int br_manje = n - br_vise;
	cout << br_vise + br_manje + 1 << endl;
	return 0;
}