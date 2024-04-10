#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int h, w;
	scanf("%d%d", &h, &w);
	vector<vector<bool>> is_plate(h, vector<bool>(w));
	for(int row : {0, h - 1}) {
		for(int col : {0, w - 1}) {
			is_plate[row][col] = true;
		}
	}
	
	for(int row = 2; row <= h - 3; row += 2) {
		is_plate[row][0] = is_plate[row][w-1] = true;
	}
	for(int col = 2; col <= w - 3; col += 2) {
		is_plate[0][col] = is_plate[h-1][col] = true;
	}
	
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			printf(is_plate[row][col] ? "1" : "0");
		}
		puts("");
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}