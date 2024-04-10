#include<bits/stdc++.h>

using namespace std;

const int MAXN = 4e3;

typedef pair<int, int> pii;
typedef pair<int, pii> candy;
#define T second.first
#define M second.second
#define H first

int N, X;
candy C[MAXN];

int go(int t) {

	priority_queue<int> q[2];
	int i = 0;
	int j = X;
	while(i < N && C[i].H <= j) {
		q[C[i].T].push(C[i].M);
		i++;
	}
	int res = 0;
	while(!q[t].empty()) {
		j += q[t].top();
		q[t].pop();
		res++;
		while(i < N && C[i].H <= j) {
			q[C[i].T].push(C[i].M);
			i++;
		}
		t = !t;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> X;
	for(int i = 0; i < N; i++) {
		cin >> C[i].T >> C[i].H >> C[i].M;
	}
	sort(C, C + N);
	int res = max(go(0), go(1));
	cout << res << '\n';
	return 0;
}