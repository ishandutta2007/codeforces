#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int req = (n + k - 1)/k;
	if(req*t > d + t){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}

	return 0;
}