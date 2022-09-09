#include<bits/stdc++.h>
using namespace std;
int read(){
	int x = 0;
	char c;
	bool pos = true;
	do{
		c = getchar();
		if(c == '-') pos = false;
	}while(c < '0' or c > '9');
	do{
		x = x * 10 + c - '0';
		c = getchar();
	}while(c >= '0'  and c <= '9');
	return pos ? x : - x;
}


int main(){
	long long n = read(), A = read(), B = read(), sum = 0;
	long long *s = new long long[n];
	for(int i = 0; i < n; i += 1) s[i] = read(), sum += s[i];
	if(A * s[0] >= B * sum){
		printf("0\n");
		return 0;
	}
	sort(s + 1, s + n);
	for(int i = n - 1; i >= 1; i -= 1) {
		sum -= s[i];
		if(A * s[0] >= B * sum){
			printf("%d\n", n - i);
			return 0;
		}
	}
	
}

//long long?10 ^18int?10^9