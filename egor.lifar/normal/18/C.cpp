#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
	int n, a[100000];
	scanf("%d", &n);
	long long s = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		 s += a[i];
	}


	long long k = s / 2;
	if(s % 2 != 0){
		printf("0\n");
		return 0;
	}
	long long p = 0;
	int r = 0;
	for(int i = 0; i < n - 1; i++){
		p += a[i];
		if(p == k){
			r++;
		}
	}
	printf("%d\n", r);

	return 0;
}