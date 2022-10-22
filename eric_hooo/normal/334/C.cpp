#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, power = 3;
	cin >> n;
	while (n % power == 0) power *= 3;
	cout << n / power + 1 << endl;
	return 0;
}