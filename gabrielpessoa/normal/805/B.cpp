#include <bits/stdc++.h>
using namespace std;

int main() {	
	int x;
	cin >> x;
	while(x > 3) {
	    printf("aabb");
	    x -= 4;
	}
	if(x == 3) {
	    printf("aab");
	}
	if(x == 2) {
	    printf("aa");
	}
	if(x == 1) {
	    printf("a");
	}
	return 0;
}