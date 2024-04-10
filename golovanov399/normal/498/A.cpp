#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

	int x[2][2];
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			cin >> x[i][j];
		}
	}
	int n;
	cin >> n;
	int ans = 0;
	for (itn i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		bool B[2];
		for (int i = 0; i < 2; i++){
			B[i] = (1ll * a * x[i][0] + 1ll * b * x[i][1] + c > 0);
		}
		if (B[0] != B[1])
			ans++;
	}
	cout << ans << "\n";

	return 0;
}