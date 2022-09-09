#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << 3 * n + min(k - 1, n - k);
}