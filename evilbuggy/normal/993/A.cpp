#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[4], b[4], c[4], d[4];
	for(int i = 0; i < 4; i++){
		cin >> a[i] >> b[i];
		a[i] <<= 1;
		b[i] <<= 1;
	}
	int cx1 = (a[0] + a[1] + a[2] + a[3])/4;
	int cy1 = (b[0] + b[1] + b[2] + b[3])/4;
	int dist1 = abs(cx1 - a[0]);
	for(int i = 0; i < 4; i++){
		cin >> c[i] >> d[i];
		c[i] <<= 1;
		d[i] <<= 1;
	}
	int cx2 = (c[0] + c[1] + c[2] + c[3])/4;
	int cy2 = (d[0] + d[1] + d[2] + d[3])/4;
	int dist2 = abs(cx2 - c[0]) + abs(cy2 - d[0]);
	for(int x = -200; x <= 200; x++){
		if(abs(x - cx1) > dist1)continue;
		for(int y = -200; y <= 200; y++){
			if(abs(y - cy1) > dist1)continue;
			if(abs(x - cx2) + abs(y - cy2) <= dist2){
				cout << "YES" << '\n';
				exit(0);
			}
		}
	}
	cout << "NO" << '\n';

	return 0;
}