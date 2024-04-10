#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	cout << (b >= a and c >= a ? "Yes" : "No");
	return 0;
}