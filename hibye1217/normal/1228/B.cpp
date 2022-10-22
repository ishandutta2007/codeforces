#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001];

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++){
		int x;
		scanf("%d", &x);
		if (x == 0) a[i][0] = -1;
		else{
			for (int j = 0; j < x; j++) a[i][j] = 1;
			a[i][x] = -1;
		}
	}
	for (int i = 0; i < w; i++){
		int x;
		scanf("%d", &x);
		if (x == 0 && a[0][i] == 1){
			printf("0");
			return 0;
		}
		for (int j = 0; j < x; j++){
			if (a[j][i] == -1){
				printf("0");
				return 0;
			}
			a[j][i] = 1;
		}
		if (a[x][i] == 1){
			printf("0");
			return 0;
		}
		a[x][i] = -1;
	}
	int cnt = 0;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++) if (a[i][j] == 0) cnt++;
	}
	long long int ans=1;
	for (int i = 0; i < cnt; i++){
		ans *= 2;
		ans %= 1000000007;
	}
	cout << ans;
}