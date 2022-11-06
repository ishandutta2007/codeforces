#include<bits/stdc++.h>
#define maxn 19260817
using namespace std;
typedef long long LL; 

int main(){
	LL n, a = 0;
	scanf("%lld", &n);
	while((1LL << a) - 1 < n) a += 1;
	printf("%lld", a);
}