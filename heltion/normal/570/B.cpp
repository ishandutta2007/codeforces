#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	int n, m;
	cin >> n >> m;
	if(m - 1 >= n - m) cout << max(m - 1, 1);
	else cout << min(m + 1, n);
}