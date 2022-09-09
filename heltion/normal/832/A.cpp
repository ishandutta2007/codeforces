#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	LL n, k;
	cin >> n >> k;
	cout << ((n / k) & 1 ? "YES" : "NO");
}