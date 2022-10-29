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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[N], b[N], n, x;
map <int, int> S;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		S[a[i]]++;
	}
	for (int i = 0; i < n - 1; i++){
		scanf("%d", &b[i]);
		S[b[i]]--;
	}
	for (int i = 0; i < n; i++)
	if (S[a[i]]){
		printf("%d\n", a[i]);
		break;
	}
	S.clear();
	for (int i = 0; i < n - 1; i++)
		S[b[i]]++;
	for (int i = 0; i < n - 2; i++){
		scanf("%d", &x);
		S[x]--;	
	}
	for (int i = 0; i < n - 1; i++)
	if (S[b[i]]){
		printf("%d\n", b[i]);
		break;
	}
}