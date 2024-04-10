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

const int size = 100 * 1000;

string num[size];

int main() {
	int n;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int ans = 0;
	for (int i = 0; i < num[0].length(); i++)
	{
		bool flag = true;
		for (int j = 1; j < n; j++)
			flag = flag && (num[j][i] == num[0][i]);
		if (flag)
			ans++;
		else
			break;
	}
	cout << ans << endl;

	return 0;
}