#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if(n%3 != 2){
		cout << 1 << " " << 1 << " " << n - 2 << endl;
	}else{
		cout << 1 << " " << 2 << " " << n - 3 << endl;
	}

	return 0;
}