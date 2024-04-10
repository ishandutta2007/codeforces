#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
char s[maxn];
int a[maxn];
int f[3][maxn];
char g(int i){
	if(i == 0) return 'R';
	if(i == 1) return 'G';
	return 'B';
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1){
		if(s[i] == 'R') a[i] = 0;
		if(s[i] == 'G') a[i] = 1;
		if(s[i] == 'B') a[i] = 2;
	}
	f[0][0] = f[1][0] = f[2][0] = 1;
	f[a[0]][0] = 0;
	for(int i = 1; i < n; i += 1){
		f[0][i] = f[1][i] = f[2][i] = i;
		for(int j = 0; j < 3; j += 1)
			for(int k = 0; k < 3; k += 1) if(j != k){
				f[k][i] = min(f[k][i], f[j][i - 1] + (a[i] != k));
			}
		}
	int m = min(min(f[0][n - 1], f[1][n - 1]), f[2][n - 1]), j = 4;
	cout << m << endl;
	string x;
	for(int i = n - 1; i >= 0; i -= 1){
		for(int k = 0; k < 3; k += 1) if(f[k][i] == m && j != k){
			x += g(k);
			m -= (k != a[i]);
			j = k;
			break;
		}
	}
	reverse(x.begin(), x.end());
	cout << x;
}