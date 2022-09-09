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
	int n = read(), s = read();
	int *A  = new int [n + 1];
	A[0] = 0;
	for(int i = 1; i <= n; i += 1){
		int h = read(), m = read();
		A[i] = 60 * h + m;
	}
	if(A[1] > s){
		printf("0 0\n");
		return 0;
	}
	for(int i = 1; i < n; i += 1){
		if(A[i] + s + 1 <= A[i + 1] - s - 1){
			int ans = A[i] + s + 1;
			printf("%d %d\n", ans / 60, ans % 60);
			return 0;
		}
	}
	int ans = A[n] + s + 1;
	printf("%d %d\n", ans / 60, ans % 60);
	return 0;
}

//long long?10 ^18int?10^9