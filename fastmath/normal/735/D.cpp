#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


bool check(int n){
	int q = ceil(sqrt(n));

	for (int i = 2; i < min(q + 1, n); i++){
		if (!(n % i)){
			return false;
		}
	}

	return true;
}


int main(){
	int n;
	cin >> n;

	if (check(n)){
		cout << 1;
	}
	else if (!(n % 2)){
		cout << 2;
	}
	else if (check(n - 2)){
		cout << 2;
	}
	else{
		cout << 3;
	}
	return 0;
}