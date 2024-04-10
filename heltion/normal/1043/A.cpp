#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, maxa = 0, s = 0;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> a;
		maxa = max(maxa, a);
		s += a;
	}
	int k = (s * 2 + n) / n;
	cout << max(maxa, k);
}