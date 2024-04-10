#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e6;
const int MAXK = MAXN;
int N, K;
int P[MAXN];
int B[MAXK];

bool keep[MAXN];
int pos[MAXN];

int bit[MAXN];

void insert(int n, int v) {
	while(n <= N) {
		bit[n] = max(bit[n], v);
		n += n & (-n);
	}
}

int query(int n) {
	int res = -1;
	while(n > 0) {
		res = max(res, bit[n]);
		n -= n & (-n);
	}
	return res;
}

int bit2[MAXN];
void insert2(int n, int v) {
	while(n <= N) {
		bit2[n] += v;
		n += n & (-n);
	}
}
int query2(int n) {
	int res = 0;
	while(n > 0) {
		res += bit2[n];
		n -= n & (-n);
	}
	return res;
}

ll lSum() {
	for(int i = 0; i < N; i++) {
		pos[P[i]] = i;
	}
	memset(keep, 0, sizeof(keep));
	for(int i = 0; i < K; i++) {
		keep[B[i]] = true;
	}
	memset(bit, -1, sizeof(bit));
	memset(bit2, 0, sizeof(bit2));
	ll res = 0;
	for(int i = 0; i < N; i++) {
		int p = pos[i];
		if(keep[i]) {
			insert(p + 1, p);
			//cerr << i << ' ' << p << '\n';
			//for(int i = 1; i <= N; i++) cerr << bit[i] << ' '; cerr << '\n';
		} else {
			int st = query(p + 1);
			//cerr << i << ' ' << p << ' ' << st << '\n';
			res += p - st - (query2(p + 1) - query2(st + 1)) - 1;
			insert2(p + 1, 1);
		}
	}
	return res;
}

ll lslow() {
	for(int i = 0; i < N; i++) {
		pos[P[i]] = i;
	}
	memset(keep, 0, sizeof(keep));
	for(int i = 0; i < K; i++) {
		keep[B[i]] = true;
	}
	int res = 0;
	for(int i = 0; i < N; i++) {
		if(keep[i]) continue;
		int p = pos[i];
		for(int j = p - 1; j >= 0; j--) {
			if(P[j] > i) res++;
			else if(keep[P[j]]) break;
		}
	}
	return res;
}

void test() {
	N = 4, K = 2;
	for(P[0] = 0; P[0] < 4; P[0] ++) {
		for(P[1] = 0; P[1] < 4; P[1] ++) {
			if(P[0] == P[1]) continue;
			for(P[2] = 0; P[2] < 4; P[2] ++) {
				if(P[0] == P[2] || P[1] == P[2]) continue;
				P[3] = 6 - P[0] - P[1] - P[2];
				for(B[0] = 0; B[0] < 4; B[0]++) {
					for(B[1] = B[0] + 1; B[1] < 4; B[1] ++) {
						if(lSum() != lslow()) {
							for(int i = 0; i < 4; i++) cout << P[i] << ' '; cout << '\n';
							cout << B[0] << ' ' << B[1] << '\n';
							cout << lSum() << ' ' << lslow() << '\n';
						}
					}
				}
			}
		}
	}
}

ll go() {
	ll res = N - K;
	res += lSum();
	reverse(P, P + N);
	//reverse(B, B + K);
	res += lSum();
	return res;
}

int main() {
	//test();
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> P[i]; P[i] --;
		pos[P[i]] = i;
	}
	for(int i = 0; i < K; i++) {
		cin >> B[i]; B[i] --;
	}
	cout << go() << '\n';
}