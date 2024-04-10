#include <bits/stdc++.h>
using namespace std;

const int logN = 30;
const int maxN = 200005;
const int lim = 1 << 30;

int ptr, T[maxN], sum[maxN*logN], child[maxN*logN][2];

void update(int v, int l, int r, int i, int x){
	if(i < l || r < i)return;
	if(l == r){
		sum[v] += x;
		return;
	}
	int m = (l + r)/2;
	if(i <= m){
		if(child[v][0] == -1){
			child[v][0] = ptr++;
		}
		update(child[v][0], l, m, i, x);
		sum[v] += x;
	}else{
		if(child[v][1] == -1){
			child[v][1] = ptr++;
		}
		update(child[v][1], m + 1, r, i, x);
		sum[v] += x;
	}
}

int querysum(int v, int s, int e, int l, int r){
	if(v == -1)return 0;
	if(e < l || r < s)return 0;
	if(l <= s && e <= r)return sum[v];

	int m = (s + e)/2;
	return querysum(child[v][0], s, m, l, r) + querysum(child[v][1], m + 1, e, l, r);
}

int querylower(int v, int l, int r, int cur, int x){
	if(l == r)return 0;
	int m = (l + r) >> 1;

	int val = cur;
	if(child[v][0] != -1){
		val += sum[child[v][0]];
	}

	if(x < val + m){
		if(child[v][0] != -1)return querylower(child[v][0], l, m, cur, x);
		return max(x - cur + 1, l);
	}else{
		if(child[v][1] != -1)return querylower(child[v][1], m + 1, r, val, x);
		return max(x - val + 1, m + 1);
	}
}

void init(){
	ptr = 1;
	memset(sum, 0, sizeof(sum));
	memset(child, -1, sizeof(child));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n;
	cin >> n;
	int lastans = 0, val0 = 0;
	for(int i = 1; i <= n; i++){
		cin >> T[i];
		if(T[i] < val0){
			update(0, 0, lim - 1, 0, -1);
		}else{
			int ind = querylower(0, 0, lim - 1, 0, T[i]);
			update(0, 0, lim - 1, ind, -1);
		}

		if(val0 < T[i]){
			int ind = querylower(0, 0, lim - 1, 0, T[i] - 1);
			update(0, 0, lim - 1, 0, 1);
			update(0, 0, lim - 1, ind, -1);
		}

		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			x = (x + lastans)%1000000001;
			cout << (lastans = x + querysum(0, 0, lim - 1, 0, x)) << '\n';
		}

		if(val0 < T[i]){
			val0++;
		}else if(val0 > T[i]){
			val0--;
		}
	}

	return 0;
}