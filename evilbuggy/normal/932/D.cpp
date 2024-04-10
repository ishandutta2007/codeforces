#include <bits/stdc++.h>
using namespace std;

const int K = 20;
const int N = 400005;

long long w[N], maxi[N], sum[N][K];
int n, nxt[N][K];

inline void init(){
	memset(nxt[0], 0, sizeof(nxt[0]));
	memset(nxt[1], 0, sizeof(nxt[1]));
	memset(sum[0], 0, sizeof(sum[0]));
	nxt[1][0] = 1;
	maxi[1] = 0;
	n = 2;
}

inline void add(int p, long long q){
	w[n] = q;
	maxi[n] = max(maxi[p], w[n]);
	nxt[n][0] = n;
	if(maxi[p] < w[n]){
		nxt[n][1] = 0;
	}else{
		nxt[n][1] = p;
		while(w[nxt[n][1]] < w[n]){
			nxt[n][1] = nxt[nxt[n][1]][1];
		}
	}
	sum[n][0] = w[n];
	sum[n][1] = sum[n][0] + w[nxt[n][1]];
	for(int i = 2; i < K; i++){
		nxt[n][i] = nxt[nxt[nxt[n][i - 1]][1]][i - 1];
		sum[n][i] = sum[n][i - 1] + sum[nxt[nxt[n][i - 1]][1]][i - 1];
	}
	++n;
}

inline int query(int p, long long q){
	int ret = 0;
	for(int i = K - 1; i >= 0; i--){
		if(nxt[p][i] && sum[p][i] <= q){
			q -= sum[p][i];
			ret ^= (1 << i);
			p = nxt[nxt[p][i]][1];
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int Q;
	cin >> Q;
	int type;
	long long p, q, last = 0;
	while(Q--){
		cin >> type >> p >> q;
		p ^= last;
		q ^= last;
		if(type == 1){
			add(p, q);
		}else{
			last = query(p, q);
			cout << last << '\n';
		}
	}

	return 0;
}