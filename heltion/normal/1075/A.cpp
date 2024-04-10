#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n, x, y;
	cin >> n >> x >> y;
	LL w = max(x - 1, y - 1);
	LL b = max(n - x, n - y);
	cout << (w <= b ? "White" : "Black");
}