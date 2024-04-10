#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	if(a <= b - c || n < b){
		cout << n/a << '\n';
	}else{
		long long l = (n - c)/(b - c);
		cout << max(n/a, l + (n - l*(b - c))/a) << '\n';
	}

	return 0;
}