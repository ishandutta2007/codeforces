#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[1005], pos = -1, info = 0, changes = 0, direction = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
	    scanf("%d", &a[i]);
	}
	while(info < n) {
	    pos += direction;
	    if(direction == 1 && pos == n) {
	        direction = -1;
	        pos -= 2;
	        changes++;
	    } else if(direction == -1 && pos == -1) {
	        direction = 1;
	        pos += 2;
	        changes++;
	    }
	    if(a[pos] <= info) {
	        info++;
	        a[pos] = 2000;
	    }
	}
	printf("%d", changes);
	return 0;
}