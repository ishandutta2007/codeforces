#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, c[N], mem[N][N][2];

int dp(int l, int r, int p){
	if(l == 1 && r == n)return 0;
	if(mem[l][r][p] != -1){
		return mem[l][r][p];
	}
	int ret = n;
	int col = (p == 0)?c[l]:c[r];
	if(l != 1){
		if(col == c[l - 1]){
			ret = min(ret, dp(l - 1, r, 0));
		}else{
			ret = min(ret, dp(l - 1, r, 0) + 1);
		}
	}
	if(r != n){
		if(col == c[r + 1]){
			ret = min(ret, dp(l, r + 1, 1));
		}else{
			ret = min(ret, dp(l, r + 1, 1) + 1);
		}
	}
	return mem[l][r][p] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int iter = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(iter == 0 || c[iter] != x){
			++iter;
			c[iter] = x;
		}
	}
	n = iter;
	int answer = n;
	memset(mem, -1, sizeof(mem));
	for(int i = 1; i <= n; i++){
		answer = min(answer, dp(i, i, 0));
	}
	cout << answer << '\n';

	return 0;
}