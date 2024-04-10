#pragma comment(linker, "/STACK:1000000000")
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

const int size = 1000 * 200;
const int alsize = 26;

int ans[size][alsize], pr[alsize];
char str[size], bad[10];

int main() {
	int len, n;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> str;
	len = strlen(str);
	while (str[len - 1] == '\n')
		len--;
	str[len] = '\0';
	cin >> n;
	for (int i = 0; i < 26; i++)
		pr[i] = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> bad;
		pr[bad[0] - 'a'] = bad[1] - 'a';
		pr[bad[1] - 'a'] = bad[0] - 'a';
	}
	for (int i = 0; i < 26; i++)
		ans[0][i] = 0;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < 26; j++)
			ans[i][j] = ans[i - 1][j] + 1;
		for (int j = 0; j < 26; j++)
			if (pr[str[i - 1] - 'a'] != j)
				ans[i][str[i - 1] - 'a'] = min(ans[i][str[i - 1] - 'a'], ans[i - 1][j]);
	}
	int answer = len;
	for (int i = 0; i < 26; i++)
		answer = min(answer, ans[len][i]);
	cout << answer;

	return 0;
}