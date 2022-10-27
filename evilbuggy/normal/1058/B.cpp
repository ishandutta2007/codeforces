#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;

	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		if(d <= x + y && x + y <= 2*n - d && x - y >= -d && x - y <= d){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << '\n';
	}

	return 0;
}