#include<bits/stdc++.h>
using namespace std;

int M, T, R;

int W[400];

bool candle[1000];
int candles[1000];

int main() {
	cin >> M >> T >> R;
	for(int i = 0; i < M; i++) {
		cin >> W[i];
	}

	int cnt = 0;
	for(int i = 0; i < M; i++) {
		while(candles[W[i] + T] < R) {
			bool found = false;
			for(int t = W[i]; t > -T; t--) {
				if(!candle[t + T]) {
					cnt++;
					candle[t + T] = true;
					for(int v = 0; v < T; v++) {
						candles[t + v + T] ++;
					}
					found = true;
					break;
				}
			}
			if(!found) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}