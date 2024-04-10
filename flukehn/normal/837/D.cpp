#include<bits/stdc++.h>
using namespace std;
const int N=5155;
int f[205][N+20];
int main(){
	ios::sync_with_stdio(0);
	int n,K;
	long long x;
	cin>>n>>K;
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++){
		cin >> x;
		int a = 0, b = 0;
		while (x % 2 == 0) a++, x /= 2;
		while (x % 5 == 0) b++, x /= 5;
		for(int i = K; i > 1; i--){
			for (int j = b; j <= N; j++)
				if(~f[i-1][j-b]) f[i][j] = max(f[i][j], f[i-1][j-b] + a);
		}
		f[1][b] = max(f[1][b], a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, min(i, f[K][i]));
	cout << ans << endl; 
}