#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int A, B, C, D; cin >> A >> B >> C >> D;
		int X, Y, X1, Y1, X2, Y2; cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2;
		cout << (X1 <= X-A+B && X-A+B <= X2 && Y1 <= Y-C+D && Y-C+D <= Y2 && (X2>X1 || (A+B==0)) && (Y2>Y1 || (C+D==0)) ? "Yes" : "No") << '\n';
	}

	return 0;
}