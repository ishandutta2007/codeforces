#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
int s[maxn];
int main(){
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		s[i] = - (a + b + c + d);
		if(i == 0) sum = a + b + c + d;
	}
	sort(s, s + n);
	for(int i = 0; i < n; i += 1){
		if(-s[i] == sum){
			printf("%d\n", i + 1);
			return 0;
		}
	}
}