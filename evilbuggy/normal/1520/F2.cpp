#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int B = 25;

int f[N/B + 5], blk[N], st[N], en[N];

inline void update(int i, int x, int n){
	while(i <= n){
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i){
	int ret = 0;
	while(i){
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

inline int findBlock(int lo, int hi, int req){
	while(lo < hi){
		int mi = lo + (hi - lo)/2;
		if(query(mi) >= req)hi = mi;
		else lo = mi + 1;
	}
	return lo;
}

inline int ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	int x; cin >> x; return r - l + 1 - x;
}

inline int findIndex(int lo, int hi, int req){
	// cout << lo << " " << hi << " " << req << endl;
	int st = lo;
	while(lo < hi){
		int mi = lo + (hi - lo)/2;
		// cout << lo << " " << mi << " " << hi << " YO" << endl;
		if(ask(st, mi) >= req)hi = mi;
		else lo = mi + 1;
	}
	return lo;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		blk[i] = (i - 1)/B + 1;
		if(i%B == 1)st[blk[i]] = i;
		en[blk[i]] = i;
	}
	int k; cin >> k;
	int m = blk[n];
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= m; i++){
		update(i, ask(st[i], en[i]), m);
	}
	for(int i =  0; i < t; i++){
		if(i)cin >> k;
		int b = findBlock(1, m, k);
		int j = findIndex(st[b], en[b], k - query(b - 1));
		cout << "! " << j << endl;
		update(b, -1, m);
	}

	return 0;
}