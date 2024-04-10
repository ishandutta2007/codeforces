#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	int minj = 0x3f3f3f3f, pos;
	for (int i = 1; i <= n; i++){
		int s, d; cin >> s >> d;
		while (s < t) s += d;
		if (s - t < minj) minj = s - t, pos = i;
	} 
	cout << pos << endl;
	return 0;
}