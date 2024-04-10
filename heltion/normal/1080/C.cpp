#include<bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
LL W, B;
LL x[4], y[4];
void PaintW(LL L, LL D, LL R, LL U){
	//cout << "PaintW: " << L << " " << D << " " << R << " " << U << endl;
	LL T = ((D + L) % 2 + (U - D + 1) * (R - L + 1)) / 2;
	W += T;
	B -= T; 
}
void PaintB(LL L, LL D, LL R, LL U){
	LL T = ((D + L + 1) % 2 + (U - D + 1) * (R - L + 1)) / 2;
	W -= T;
	B += T; 
}
void PaintW(LL L, LL D, LL R, LL U, int s){
	//cout << "PaintW: " << L << " " << D << " " << R << " " << U << " " << s << endl;
	if(s == 0){
		if(U > y[3] && D <= y[3]){
			PaintW(L, y[3] + 1, R, U);
			PaintW(L, D, R, y[3], 1);
		}
		else if(D > y[3]) PaintW(L, D, R, U);
		else PaintW(L, D, R, U, 1);
	}
	if(s == 1){
		if(D < y[2] && U >= y[2]){
			PaintW(L, D, R, y[2] - 1);
			PaintW(L, y[2], R, U, 2);
		}
		else if(U < y[2]) PaintW(L, D, R, U);
		else PaintW(L, D, R, U, 2);
	}
	if(s == 2){
		if(R > x[3] && L <= x[3]){
			PaintW(x[3] + 1, D, R, U);
			PaintW(L, D, x[3], U, 3);
		}
		else if(L > x[3]) PaintW(L, D, R, U);
		else PaintW(L, D, R, U, 3);
	}
	if(s == 3){
		if(L < x[2] && R >= x[2]){
			PaintW(L, D, x[2] - 1, U);
			PaintW(L, x[2], R, U, 4);
		}
		else if(R < x[2]) PaintW(L, D, R, U);
		else PaintW(L, D, R, U, 4);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		LL n, m;
		cin >> n >> m;
		for(int i = 0; i < 4; i += 1) cin >> x[i] >> y[i];
		B = n * m / 2, W = n * m - B;
		PaintW(x[0], y[0], x[1], y[1], 0);
		PaintB(x[2], y[2], x[3], y[3]);
		cout << W << " " << B << endl;
	}
}