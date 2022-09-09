#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
int a[2][maxn];
int main(){
	int n;
	cin >> n;
	if(n == 3){
		cout << "1 2 3";
		return 0;
	}
	for(int i = 1; i <= n; i += 1) cin >> a[0][i] >> a[1][i];
	for(int i = 1; i <= n; i += 1)
		if(a[0][a[0][i]] != a[1][i] && a[1][a[0][i]] != a[1][i])
			swap(a[0][i], a[1][i]);
	for(int i = 1, p = 1; i <= n; i += 1, p = a[0][p])
		cout << p << " ";
}