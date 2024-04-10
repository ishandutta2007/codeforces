#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int lis = n, lds = 1;
	for(int i = 1; i <= n; i++){
		int j = (n + i - 1)/i;
		if(i + j < lis + lds){
			lis = i;
			lds = j;
		}
	}
	for(int i = 0, j = 1; i < lis; i++){
		int cnt = n/lis;
		if(i < (n%lis))cnt++;
		for(int k = 1; k <= cnt; k++){
			cout << j + cnt - k << " ";
		}
		j += cnt;
	}
	cout << '\n';

	return 0;
}