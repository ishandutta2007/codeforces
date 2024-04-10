#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	int a[10000];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if ((a[i - 1] == j) && (a[j - 1] == i)){
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}