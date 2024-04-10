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

char maybe[] = {'U', 'D', 'L', 'R'};
char type[] = {1, 1, 0, 0};

int main() {

	bool used[4];
	int n;
	long long s1 = 1, s2 = 1;
	string str;
	long long ans = 0;
	
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str.length() == 4)
			s1++, s2++;
		else
		if (str == "UR" || str == "DL")
			s1++;
		else
			s2++;
	}
	cout << s1 * s2 << endl;

	return 0;
}