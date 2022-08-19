#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e4;
const int MAXM = 4e4;

const int MAXT = 2e5;

int N, M, T;

int S[MAXN];

int R;
int U[MAXN];

const int MAXR = MAXN;
int cnt[MAXR];

bool go() {
	bool good = false;
	int numU = 0;
	int l = 0;
	for(int i = 0; i < N; i++) {
		int t = S[i];
		while(l < i && S[l] + T <= t) {
			if(!(--cnt[U[l]])) numU --;
			l++;
		}
		if(numU == M) {
			U[i] = U[i - 1];
		} else {
			numU ++;
			U[i] = R++;
			if(numU == M) good = true;
		}

		cnt[U[i]] ++;
	}

	return good;
}

int main() {
	scanf("%d %d %d", &N, &M, &T);
	for(int i = 0; i < N; i++) {
		int h, m, s;
		scanf(" %d:%d:%d", &h, &m, &s);
		S[i] = ((h * 60) + m) * 60 + s;
	}


	if(go()) {
		printf("%d\n", R);
		for(int i = 0; i < N; i++) {
			printf("%d\n", U[i] + 1);
		}
	} else {
		printf("No solution\n");
	}
	return 0;
}