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

int cnt[26];

int main(){
	int n, ans = 0; char a, b;
	scanf("%d", &n);
	n--;
	for (int i = 0; i < n; i++){
		scanf(" %c%c", &a, &b);
		cnt[a - 'a']++;	
		if (cnt[b - 'A'])
			cnt[b - 'A']--;
		else ans++;
	}
	printf("%d\n", ans);
}