#include <set>
#include <map>
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

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int a[500], m, t, r;

map <int, int> S;

int main(){
	scanf("%d%d%d", &m,  &t, &r);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a, a + m);
	int ans = 0;
	for (int i = 0; i < m; i++){
		int cnt = 0;
		for (int j = a[i]; j > a[i] - t; j--)
		if (S[j] == 1) cnt++;
		for (int j = a[i]; j > a[i] - t; j--)
		if (S[j] == 0 && cnt < r){
			cnt++;
			S[j] = 1;
			ans++;
		}
		if (cnt < r){
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", ans);
}