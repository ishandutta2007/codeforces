#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int x = 0;
	for(int i = 0; i < n; i++){
		int y;
		cin >> y;
		x = x | y;
	}
	if(x){
		cout << "HARD";
	}else{
		cout << "EASY";
	}
	cout << '\n';

	return 0;
}