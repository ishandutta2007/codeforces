#include <bits/stdc++.h>

using namespace std;

int x;

int main() {
	scanf("%d", &x);
	
	int mini = (x / 7) * 2 + (x % 7 == 6);
	int maxi = 0;
	
	maxi = (x / 7) * 2;
	if(x % 7 == 1) maxi += 1;
	if(x % 7 >= 2) maxi += 2;
	
	printf("%d %d\n", mini, maxi);
	return 0;
}