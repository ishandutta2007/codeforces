#include <bits/stdc++.h>
using namespace std;

const int N = 222222;
const int M = 444444;
int n, m, a[N], f[M];

inline void update(int i){
	i += N;
	while(i < M){
		f[i] += 1;
		i += i&(-i);
	}
}

inline int query(int i){
	i += N;
	int ret = 0;
	while(i){
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

long long count(int x){
	memset(f, 0, sizeof(f));
	long long ret = 0; update(0);
	for(int i = 1, cnt = 0; i <= n; i++){
		if(a[i] >= x)cnt++;
		ret += query(2*cnt - i - 1);
		update(2*cnt - i);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << count(m) - count(m + 1) << '\n';

	return 0;
}