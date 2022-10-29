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


char s[222222];
int sum[222222];

int n, x;

int main(){
	scanf("%s", s + 1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		sum[x]++;
	}
	int m = strlen(s + 1);
	for (int i = 1; i <= m / 2; i++){
		sum[i] = sum[i - 1] + sum[i];
		if (sum[i] & 1) swap(s[i], s[m - i + 1]);
	}
	printf("%s\n", s + 1);
}