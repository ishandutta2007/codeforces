#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	ios::sync_with_stdio(false);

	int y, b, r;
	cin >> y >> b >> r;
	cout << min(min(y, b - 1), r - 2) * 3 + 3;

	return 0;
}