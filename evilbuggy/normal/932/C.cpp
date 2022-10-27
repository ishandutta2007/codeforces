#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	for(int x = 0; x*a <= n; x++){
		if((n - x*a)%b == 0){
			int y = (n - x*a)/b;
			int iter = 0;
			while(x--){
				for(int i = 2; i <= a; i++){
					cout << iter + i << " ";
				}
				cout << iter + 1 << " ";
				iter += a;
			}
			while(y--){
				for(int i = 2; i <= b; i++){
					cout << iter + i << " ";
				}
				cout << iter + 1 << " ";
				iter += b;
			}
			cout << '\n';
			exit(0);
		}
	}
	cout << -1 << '\n';

	return 0;
}