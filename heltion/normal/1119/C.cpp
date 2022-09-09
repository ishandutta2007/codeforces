#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600;
void no(){
	cout << "No";
	exit(0);
}
int a[maxn][maxn], b[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			cin >> a[i][j];
	
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			cin >> b[i][j];
	
	
	for(int i = 0; i + 1 < n; i += 1)
		for(int j = 0; j + 1 < m; j += 1)
			if(a[i][j] != b[i][j]){
				a[i][j] = 1 - a[i][j];
				a[i + 1][j] = 1 - a[i + 1][j];
				a[i][j + 1] = 1 - a[i][j + 1];
				a[i + 1][j + 1] = 1 - a[i + 1][j + 1];
			}
	
	
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1) if(a[i][j] != b[i][j]) no();
	cout << "Yes";
}