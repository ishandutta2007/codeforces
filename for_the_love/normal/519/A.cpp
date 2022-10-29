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


char s[10];
int a, b;
int main(){
	for (int i = 0; i < 8; i++){
		scanf("%s", s);
		for (int j = 0; j < 8; j++)
		if (s[j] == 'Q') a += 9;
		else if (s[j] == 'R') a += 5;
		else if (s[j] == 'B') a += 3;
		else if (s[j] == 'N') a += 3;
		else if (s[j] == 'P') a += 1;
		else if (s[j] == 'q') b += 9;
		else if (s[j] == 'r') b += 5;
		else if (s[j] == 'b') b += 3;
		else if (s[j] == 'n') b += 3;
		else if (s[j] == 'p') b += 1;
	}
	if (a == b) puts("Draw");
	else if (a > b) puts("White");
	else puts("Black");
}