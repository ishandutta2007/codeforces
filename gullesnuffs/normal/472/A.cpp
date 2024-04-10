#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k){
	for(int i=2; i*i <= k; ++i)
		if(k%i == 0)
			return 0;
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=4; true; ++i){
		if(!isPrime(i) && !isPrime(n-i)){
			printf("%d %d\n", i, n-i);
			return 0;
		}
	}
}