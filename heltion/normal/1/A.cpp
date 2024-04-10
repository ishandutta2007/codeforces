#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	LL n, m, a;
	cin >> n >> m >> a;
	cout << ((n + a - 1) / a) * ((m + a - 1) / a);
}