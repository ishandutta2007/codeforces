//Author: Heltion
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
void no(){
	cout << "NO";
	exit(0);
}
int d[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i < n; i += 1){
		int u, v;
		cin >> u >> v;
		d[u] += 1;
		d[v] += 1;
	}
	for(int i = 1; i <= n; i += 1) if(d[i] == 2) no();
	cout << "YES";
	return 0;
}