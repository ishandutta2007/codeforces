#include <bits/stdc++.h>
using namespace std;

const int maxN = 500005;

int a[maxN], f[maxN], chk[maxN];

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

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		chk[i] = f[i] = 0;
	}
	bool flg = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(chk[a[i]]){
			flg = false;
		}else{
			chk[a[i]] = 1;
		}
	}
	if(!flg){
		cout << "YES" << '\n';
		return;
	}
	int parity = 0;
	for(int i = n; i >= 1; i--){
		parity ^= (query(a[i])&1);
		update(a[i], 1, n);
	}
	if(parity){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}