#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool prime(int n){
	if (n == 2){
		return true;
	}
	int q = ceil(sqrt(n));
	for (int i = 2; i <= q; i++){
		if (!(n % i)){
			return false;
		}
	}

	return true;
}


int main(){
	int n;
	cin >> n;

	int last = 2;
	vector <int> a(n);
	for (int i = 2; i <= n + 1; i++){
		if (prime(i)){
			a[i - 2] = 1;
		}
		else{
			a[i - 2] = 2;
		}
	}

	if (n < 3){
		cout << 1 << endl;
	}
	else{
		cout << 2 << endl;
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}

	int l = 1;
	return 0;
}