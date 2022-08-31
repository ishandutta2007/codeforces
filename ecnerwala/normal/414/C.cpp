#include <iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

const int INF = 2e9;
const int MAXS = 2e6;


int N;
int A[MAXS];
int tmp[MAXS];

ll cntInv[50][2];

//[st, en)
void sort(int st, int sz) {
	if(sz == 0) return;
	int md = st + (1 << (sz - 1));
	int en = st + (1 << (sz));
	sort(st, sz - 1);
	sort(md, sz - 1);
	int i = st, j = md;
	while(i < md || j < en) {
		int val = INF;
		if(i < md && A[i] < val) val = A[i];
		if(j < en && A[j] < val) val = A[j];
		int pi = i - st;
		int pj = j - md;
		while(i < md && A[i] == val) {
			cntInv[sz][0] += pj;
			tmp[i - st + j - md] = val;
			i++;
		}
		while(j < en && A[j] == val) {
			cntInv[sz][1] += pi;
			tmp[i - st + j - md] = val;
			j++;
		}
	}
	for(int k = st; k < en; k++) {
		A[k] = tmp[k - st];
	}
}

int Q[50];

ll getCost() {
	int tot = 0;
	ll res = 0;
	for(int i = N; i >= 0; i--) {
		tot += Q[i]; tot %= 2;
		res += cntInv[i][tot];
	}
	return res;
}
	
int main() {
	scanf("%d", &N);
	for(int i = 0; i < (1 << N); i++) scanf("%d", &A[i]);
	sort(0, N);
	int M; scanf("%d", &M);
	//for(int i = 0; i < (1 << N); i++) cout << A[i] << ' '; cout << '\n';
	//for(int i = 1; i <= N; i++) cout << cntInv[i][0] << ' ' << cntInv[i][1] << '\n';
	for(int i = 0; i  < M; i++) {
		int q; scanf("%d", &q);
		Q[q]++;
		printf("%I64d\n", getCost());
	}
	
	return 0;
}