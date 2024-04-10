#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


const int MaxN = 1000005;
char str[MaxN], nstr[MaxN];
int N, M;


void input() {
	scanf("%s %d", str, &M);
	N = strlen(str);
}


int perm[MaxN * 2];
int nperm[MaxN * 2];
bool used[MaxN * 2];


void power(int pwr) {
	fill(used, used + 2 * N, false);
	for (int i = 0; i < 2 * N; i++) {
		if (used[i]) {
			continue;
		}
		vector<int> cycle;
		int v = i;
		do {
			used[v] = true;
			cycle.push_back(v);
			v = perm[v];
		} while(v != i);
		int jump = pwr % (int)cycle.size();
		int ptr2 = i;
		while (jump--) {
			ptr2 = perm[ptr2];
		}
		for (int i = 0; i < (int)cycle.size(); i++) {
			nperm[cycle[i]] = ptr2;
			ptr2 = perm[ptr2];
		}
	}
	copy(nperm, nperm + 2 * N, perm);
}


void first_perm() {
	for (int i = 1; i < 2 * N; i++) {
		perm[i] = i - 1;
	}
	perm[0] = 2 * N - 1;
}


int main(){
	input();
	for (int ii = 0; ii < M; ii++) {
		int k, d;
		scanf("%d %d", &k, &d);
		first_perm();	
		int ptr = N - 1;
		for (int i = 0; i < d; i++) {
			for (int j = i; j < k; j += d) {
				perm[N + j] = ptr++;
			}
		}
		power(N - k + 1);
		int incr = k - 1;
		for (int i = 0; i < N; i++) {
			nstr[perm[N + i] - incr] = str[i];
		}
		copy(nstr, nstr + N, str);
		printf("%s\n", str);
	}
	return 0;
}