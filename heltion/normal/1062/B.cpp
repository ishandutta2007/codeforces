#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, z = 0, s = 1, a = 0;
	cin >> n;
	for(int i = 2; i <= n; i += 1)if(n % i == 0){
		s *= i;
		int p = 0;
		while(n % i == 0){
			n /= i;
			p += 1;
		}
		if(p > z){
			if(z) a = 1;
			z = p;
		}
		else if(z > p) a = 1;
	}
	if(z <= 1) printf("%d %d", s, 0);
	else{
		int k = 1, b = 0;
		while(k < z){
			k *= 2;
			b += 1;
		}
		if(k != z) a = 1;
		printf("%d %d", s, a + b);
	}
}