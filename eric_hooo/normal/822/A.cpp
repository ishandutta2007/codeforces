#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b; cin >> a >> b;
	a = min(a, b);
	long long ans = 1;
	for (int i = 1; i <= a; i++){
		ans = ans * i;
	}
	cout << ans << endl;
	return 0;
}