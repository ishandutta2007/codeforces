#include <bits/stdc++.h>
using namespace std;

const int logN = 30;
const int maxN = 200005;

int A[maxN];

inline int go(int x){
	if(x&(x - 1)){
		for(int i = logN - 1; i >= 0; i--){
			if((x >> i) & 1){
				return (1 << (i + 1)) - x;
			}
		}
	}
	return 0;
}

inline int dist(int x, int y){
	int ret = 0;
	while(x != y){
		if(x > y){
			x = go(x);
		}else{
			y = go(y);
		}
		ret++;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	int ans = 0;
	int indx = 0;
	int indy = 0;
	for(int i = 0; i < N; i++){
		int tmp = dist(A[0], A[i]);
		if(tmp > ans){
			ans = tmp;
			indx = i;
		}
	}
	ans = 0;
	for(int i = 0; i < N; i++){
		int tmp = dist(A[indx], A[i]);
		if(tmp > ans){
			ans = tmp;
			indy = i;
		}
	}
	cout << indx + 1 << " " << indy + 1 << " " << ans << '\n';

	return 0;
}