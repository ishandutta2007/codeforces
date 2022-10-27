#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	if(a < x || a + b < x + y || a + b + c < x + y + z){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
	}

	return 0;
}