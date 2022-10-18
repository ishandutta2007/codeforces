/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int N, X[MAXN], M[MAXN];

int main(int argc, char *argv[]){
	scanf("%d", &N);
	REP(i, N) scanf("%d", X + i + 1);
	int L = 0;
	FOR(i, 1, N) {
		int left = 0, right = L, middle;	
		while(left < right) {
			middle = (left + right + 1) / 2;
			if (X[M[middle]] < X[i]) left = middle;
			else right = middle - 1;
		}
    if (left == L || X[i] < X[M[left+1]]) {
       M[left+1] = i;
       L = max(L, left+1);
		}
	}
	printf("%d\n", L);
	return 0;
}