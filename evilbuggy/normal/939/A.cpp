#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> f(n);
	for(int i = 0; i < n; i++){
		cin >> f[i]; f[i]--;
	}
	for(int i = 0; i < n; i++){
		if(f[f[f[i]]] == i){
			cout << "YES" << '\n';
			exit(0);
		}
	}
	cout << "NO" << '\n';

	return 0;
}