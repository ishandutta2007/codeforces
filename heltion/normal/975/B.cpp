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
	int A[14];
	for(int i = 0; i < 14; i += 1) A[i] = read();
	int B[14];
	long long ans = 0;
	for(int i = 0; i < 14; i += 1){
		long long tmp = 0;
		for(int j = 0; j < 14; j += 1) B[j] = A[j];
		int re = B[i];
		B[i] = 0;
		for(int j = 1; j <= 14; j += 1)	B[(i + j) % 14] += re / 14 + (j <= re % 14);
		for(int j = 0; j < 14; j += 1) if(B[j] % 2 == 0) tmp += B[j];
//		for(int j = 0; j < 14; j += 1) printf("%d ", B[j]);printf("\n");
		ans = max(ans, tmp);
	}
	printf("%lld", ans);
}