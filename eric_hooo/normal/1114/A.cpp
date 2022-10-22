#include <bits/stdc++.h>
using namespace std;
int main(){
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	if (a < x){
		cout << "NO" << endl;
		return 0;
	}
	a -= x;
	if (a + b < y){
		cout << "NO" << endl;
		return 0;
	}
	int sum = a + b + c;
	sum -= y;
	if (sum < z){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}