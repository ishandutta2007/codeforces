#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1100;

int res[size][size];
int used[size][size];
char help[size];
int rs[3][3];
int w1[size * size], w2[size * size];

int gameres(char c1, char c2)
{
	return rs[help[c1]][help[c2]];
}

int main() {
	help['R'] = 0;
	help['S'] = 1;
	help['P'] = 2;
	rs[0][0] = 0;
	rs[1][1] = 0;
	rs[2][2] = 0;
	rs[0][1] = 1;
	rs[0][2] = -1;
	rs[1][0] = -1;
	rs[1][2] = 1;
	rs[2][0] = 1;
	rs[2][1] = -1;

	int n;
	string st1, st2;
	
	//freopen("problemA.in", "r", stdin);
	//freopen("problemA.out", "w", stdout);
	
	cin >> n;
	cin >> st1 >> st2;
	int l1 = st1.length();
	int l2 = st2.length();
	for (int i = 0; i < l1; i++)
		for (int j = 0; j < l2; j++)
			res[i][j] = gameres(st1[i], st2[j]);
	for (int i = 0; i < l1; i++)
		for (int j = 0; j < l2; j++)
			used[i][j] = -1;
	int cnt = 0;
	int p1 = 0, p2 = 0;
	long long ans1 = 0, ans2 = 0;
	while (n > 0 && used[p1][p2] == -1)
	{
		cnt++;
		used[p1][p2] = cnt;
		n--;
		if (res[p1][p2] == 1)
			ans2++;
		if (res[p1][p2] == -1)
			ans1++;
		w1[cnt] = ans1;
		w2[cnt] = ans2;
		p1 = (p1 + 1) % l1;
		p2 = (p2 + 1) % l2;
	}
	if (used[p1][p2] != -1)
	{
		ans1 += (w1[cnt] - w1[used[p1][p2] - 1]) * (n / (cnt - used[p1][p2] + 1));
		ans2 += (w2[cnt] - w2[used[p1][p2] - 1]) * (n / (cnt - used[p1][p2] + 1));
		n %= (cnt - used[p1][p2] + 1);
	}
	while (n > 0)
	{
		if (res[p1][p2] == 1)
			ans2++;
		if (res[p1][p2] == -1)
			ans1++;
		n--;
		p1 = (p1 + 1) % l1;
		p2 = (p2 + 1) % l2;
	}
	cout << ans1 << ' ' << ans2 << endl;

	return 0;
}