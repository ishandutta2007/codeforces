#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int prev = 5000;
	bool flg = true;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a != b){
			cout << "rated" << '\n';
			exit(0);
		}
		if(prev < a){
			flg = false;
		}
		prev = a;
	}
	if(flg)cout << "maybe" << '\n';
	else cout << "unrated" << '\n';

	return 0;
}