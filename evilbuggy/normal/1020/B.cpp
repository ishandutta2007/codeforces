#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i]; p[i]--;
	}
	for(int i = 0; i < n; i++){
		vector<int> vis(n);
		int x = i;
		while(!vis[x]){
			vis[x] = 1;
			x = p[x];
		}
		cout << x + 1 << ' ';
	}
	cout << '\n';

	return 0;
}