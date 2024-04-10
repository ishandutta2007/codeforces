#include <bits/stdc++.h>
using namespace std;

const int maxN = 505;

int A[maxN][maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int cur = n*n;
	int answer = 0;
	for(int i = 1; i <= n; i++){
		for(int j = n; j >= k; j--){
			A[i][j] = cur; cur--;
		}
		answer += A[i][k];
	}
	for(int i = 1; i <= n; i++){
		for(int j = k - 1; j >= 1; j--){
			A[i][j] = cur; cur--;
		}
	}
	cout << answer << '\n';
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}