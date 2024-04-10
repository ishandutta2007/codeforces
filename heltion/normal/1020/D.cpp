#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
int n;
int a[maxn];
void query(int L, int R){
	int M = (L + R) / 2;
	printf("? %d\n", M); fflush(stdout);
	printf("? %d\n", n / 2 + M); fflush(stdout);
	scanf("%d %d", a + M, a + M + n / 2);
	if(a[M] == a[n / 2 + M]){
		printf("! %d\n", M); fflush(stdout);
		return;
	}
	if(((a[M + n / 2] - a[M]) < 0) ^ ((a[L + n / 2] - a[L]) < 0)) query(L, M);
	else query(M, R);
}
int main(){
	scanf("%d", &n);
	if(n % 4){
		printf("! -1\n"); fflush(stdout);
		return 0;
	}
	printf("? 1\n"); fflush(stdout);
	printf("? %d\n", n / 2 + 1); fflush(stdout);
	scanf("%d %d", a + 1, a + n / 2 + 1);
	if(a[1] == a[n / 2 + 1]){
		printf("! %d\n", 1); fflush(stdout);
		return 0;
	}
	printf("? %d\n", n / 2); fflush(stdout);
	printf("? %d\n", n); fflush(stdout);
	scanf("%d %d", a + n / 2, a + n);
	if(a[n / 2] == a[n]){
		printf("! %d\n", n / 2); fflush(stdout);
		return 0;
	}
	query(1, n / 2);
	
}