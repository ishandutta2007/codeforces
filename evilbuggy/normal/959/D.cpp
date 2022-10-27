#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int lpf[N], chk[N], ans[N];

void init(){
	memset(lpf, -1, sizeof(lpf));
	for(int n = 2; n*n < N; n++){
		if(lpf[n] == -1){
			for(int m = n*n; m < N; m += n){
				if(lpf[m] == -1)lpf[m] = n;
			}
		}
	}
	for(int n = 2; n < N; n++){
		if(lpf[n] == -1)lpf[n] = n;
	}
}

inline bool possible(int x){
	while(x > 1){
		if(chk[lpf[x]])return false;
		x /= lpf[x];
	}
	return true;
}

inline void insert(int x){
	while(x > 1){
		chk[lpf[x]] = 1;
		x /= lpf[x];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	memset(chk, 0, sizeof(chk));

	int n;
	cin >> n;
	int iter = 2;
	bool flg = false;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(!flg){
			if(possible(x)){
				ans[i] = x;
				insert(x);
				continue;
			}
			while(!possible(x))x++;
			ans[i] = x;
			insert(x);
			flg = true;
		}else{
			while(lpf[iter] != iter || chk[iter])iter++;
			ans[i] = iter;
			chk[iter] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';


	return 0;
}