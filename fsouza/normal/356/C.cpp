#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int solve(vector <int> &many, vector <int> &put, int acc)
{
head:

	for (int k = 4; k >= 3; k--) {
		if (many[k] < put[k]) {
			for (int i = 1; i <= k-1; i++)
				for (int j = k-1; j >= i; j--) {
					int move;
					if (i != j) move = min(min(many[i], many[j]), put[k]-many[k]);
					else move = min(many[i]/2, put[k]-many[k]);
					
					if (!move) continue;

					if (i == j)
						move = max(1, move/2);
					
					many[i] -= move;
					many[i-1] += move;
					many[j] -= move;
					many[j+1] += move;

					acc += move;
					goto head;
//					return solve(many, put, move + acc);
				}
			return INF;
		} else if (many[k] > put[k]) { /* K == 4 */
			for (int j = 2; j >= 0; j--) {
				int move = min(min(many[k], many[j]), many[k]-put[k]);

				if (!move) continue;

				if (j == 1)
					move = max(1, move/2);
				if (j == 0)
					move = max(1, move/3);

				many[j] -= move;
				many[j+1] += move;
				many[k] -= move;
				many[k-1] += move;

				acc += move;
				goto head;
//				return solve(many, put, move + acc);
			}

			return INF;
		}
	}

	return acc;
}

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);
	
	int many[5] = {0};
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		many[v] ++;
		sum += v;
	}

	int result = INF;

	for (int put3 = 0; 3*put3 <= sum; put3++) {
		if ((sum-3*put3)%4) continue;
		const int put4 = (sum - 3*put3)/4;
		
		vector <int> put(5, 0);
		
		put[3] = put3;
		put[4] = put4;

		vector <int> many2 = vector <int>(many, many+5);

		result = min(result, solve(many2, put, 0));
	}

	if (result == INF) printf("-1\n");
	else printf("%d\n", result);

	return 0;
}