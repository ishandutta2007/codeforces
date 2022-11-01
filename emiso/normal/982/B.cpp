#include <bits/stdc++.h>

using namespace std;

int n, w[200020], x;

priority_queue<pair<int, int> > empt, taken;

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		empt.push({-w[i], i + 1});
	}
	
	for(int i = 0; i < 2*n; i++) {
		scanf("%1d", &x);
		if(x == 0) {
			pair<int, int> seat = empt.top();
			empt.pop();
			taken.push({-seat.first, seat.second});
			printf("%d ", seat.second);
		} else if(x == 1) {
			pair<int, int> seat = taken.top();
			taken.pop();
			printf("%d ", seat.second);
		} else assert(false);
	}
	
	return 0;
}