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


map <PI, int> Q;
map <int, PI> P;
int main(){
	int n, m, k, x, y, t;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		P[x] = MP(i / k, i % k);
		Q[MP(i / k, i % k)] = x;
	}
	LL ans = 0;
	for (int i = 0; i < m; i++){
		scanf("%d", &t);
		ans += P[t].first + 1;
		int x = P[t].first, y = P[t].second;
		if (!x && !y) continue;
		if (!y){
			P[t] = MP(x - 1, k - 1);
			int tmp = Q[MP(x - 1, k - 1)];
			P[tmp] = MP(x, y);
			Q[MP(x - 1, k - 1)] = t;
			Q[MP(x, y)] = tmp;
		}else{
			P[t] = MP(x, y - 1);
			int tmp = Q[MP(x, y - 1)];
			P[tmp] = MP(x, y);
			Q[MP(x, y - 1)] = t;
			Q[MP(x, y)] = tmp; 
		}
	} 	
	printf("%I64d\n", ans);
	
}