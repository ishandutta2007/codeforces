#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 7e2 + 72;
int g[N][N], a[N];
int mem[2][N][N];

int dp(int rt, int l, int r){
	if(l > r)return true;
	int &ret = mem[rt][l][r];
	if(~ret)return ret;
	int par = (rt == 0)?(l - 1):(r + 1);
	for(int i = l; i <= r; i++){
		if(!g[par][i])continue;
		if(dp(1, l, i - 1) && dp(0, i + 1, r))return ret = 1;
	}
	return ret = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = (__gcd(a[i], a[j]) > 1);
		}
	}
	for(int i = 0; i <= n; i++){
		g[0][i] = 1;
	}
	memset(mem, -1, sizeof(mem));
	if(dp(0, 1, n))cout<<"Yes";
	else cout<<"No";

	return 0;
}