#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector <int> a;
long long int p = 0;

int f(long long int n){
	int i = p;
	while (!(n % 2)){
		n /= 2;
		i--;
	}

	return a[i];
}

int main(){
	long long int n, l, r;
	cin >> n >> l >> r;

	if (!n){
		cout << 0;
	}
	else{
		while (n > 1){
			a.push_back(n % 2);
			n /= 2;
			p++;
		}

		a.push_back(1);
		int ans = 0;
		for (long long int i = l; i <= r; i++){
			ans += f(i);
		}

		cout << ans;
	}
	return 0;
}