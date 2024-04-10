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


char s[100005]; 
int n;


int main(){
	scanf("%s", s);
	n = strlen(s);
	int mx = -100, pos = -1;
	for (int i = 0; i < n - 1; i++)
	if ((s[i] - '0' & 1) == 0){
		if (s[n - 1] - s[i] > 0){
			swap(s[n - 1], s[i]);
			printf("%s\n", s);
			return 0;		
		}
		
	} 
	for (int i = n - 2; i >= 0; i--)
	if ((s[i] - '0' & 1) == 0){
		if (s[n - 1] - s[i] < 0){
			swap(s[n - 1], s[i]);
			printf("%s\n", s);
			return 0;
		}
	}
	printf("%d\n", -1);
}