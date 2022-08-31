#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 2000000;
const int MAXM = 2000000;
const int MAXL = 25;

int N, M;
int A[MAXM];
int W[MAXN];

int nxt[MAXN][MAXL];

void precomp() {
	nxt[0][0] = 0;
	for(int i = 1, v = 0; i <= N; i++) {
		if(v < M && A[v] == i) {
			nxt[i][0] = 0;
			v++;
		} else {
			nxt[i][0] = i - v;
		}
	}
	for(int l = 1; (1 << l) <= N; l++) {
		for(int i = 0; i <= N; i++) {
			nxt[i][l] = nxt[nxt[i][l - 1]][l-1];
		}
	}
}

int trace(int pos, int num) {
	for(int i = 0; (1 << i) <= num; i++) {
		if(num & (1 << i)) pos = nxt[pos][i];
	}
	return pos;
}

vector<int> res;
int len;

void pop() {
	len -= upper_bound(A, A + M, len) - A;
}

void insert(int v, int numLeft) {
	len++;
	if(trace(len, numLeft)) {
		res.push_back(v);
	}
}

void go() {
	precomp();
	len = 0;

	int numLeft = 0;
	for(int i = 0; i < N; i++) {
		if(W[i] == -1)  numLeft++;
	}

	for(int i = 0; i < N; i++) {
		if(W[i] == -1) {
			pop();
			numLeft--;
		} else {
			insert(W[i], numLeft);
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> W[i];

	go();

	if(res.size() == 0) cout << "Poor stack!\n";
	else {
		for(int i = 0; i < res.size(); i++) cout << res[i];
		cout << '\n';
	}
}