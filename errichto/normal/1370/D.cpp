/*4, 8, 5, 6, 4

min(8, 5) = 5

Binary search the answer.
can answer be 4 or smaller?

5 3 50 2 4 5
1 0 1 1 1 0 0 1
  ^ ^     ^ ^
0 represents a good number (<=4)

Can I choose a subsequence of length K
so that I would have only 0's at even positions.

Go from left to right.
Take 0 if odd position, take anything if even position*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int low = 0, high = *max_element(a.begin(), a.end());
	int g_answer = -1;
	while(low <= high) {
		int answer = low + (high - low) / 2;
		bool found = false;
		for(int turn : {0, 1}) {
			int taken = 0;
			bool now_zero = turn;
			for(int x : a) {
				if(!now_zero || x <= answer) {
					taken++;
					now_zero = !now_zero;
				}
			}
			if(taken >= k) {
				found = true;
			}
		}
		if(found) {
			g_answer = answer;
			high = answer - 1;
		}
		else {
			low = answer + 1;
		}
	}
	printf("%d\n", g_answer);
}