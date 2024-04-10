#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
#define maxn
int main(){
	int n, a, s = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		scanf("%d", &a);
		s += a * i * 4;
	}
	printf("%d", s);
}