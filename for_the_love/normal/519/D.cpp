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

map <PI, int> S;
int c[26];
char s[N];

int main(){	
	for (int i = 0; i < 26; i++)
		scanf("%d", &c[i]);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	LL sum = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		int ch = s[i] - 'a';
		ans += S[MP(ch, sum)];
		sum += c[ch];
		S[MP(ch, sum)]++;	
	}
	printf("%I64d\n", ans);
}