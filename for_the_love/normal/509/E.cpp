#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


char s[555555];
double sum1[555555], sum2[555555];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		sum1[i] = sum1[i - 1] + 1.0 / i;
	for (int i = 1; i <= n; i++)
		sum2[i] = sum2[i - 1] + (double)min(n - i + 1, i) / i;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
		int t = min(i - 1, n - i) + 1;
		ans += t + (sum1[n - t] - sum1[t]) * t + sum2[n] - sum2[n - t];
	}
	printf("%.10lf\n", ans);

}