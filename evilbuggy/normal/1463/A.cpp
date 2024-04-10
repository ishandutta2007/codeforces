#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		if((a + b + c)%9 != 0){
			cout << "NO" << '\n';
		}else{
			int tot = (a + b + c)/9;
			if(min({a, b, c}) < tot){
				cout << "NO" << '\n';
			}else{
				cout << "YES" << '\n';
			}
		}
	}

	return 0;
}