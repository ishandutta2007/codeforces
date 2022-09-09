#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
char s[maxn], t[maxn];
int main(){
	int n ;
	scanf("%d %s %s", &n, s, t);
	long long a11 = 0, a10 = 0, a01 = 0, a00 = 0;
	for(int i = 0; i < n; i += 1){
		if(t[i] == '1' && s[i] == '1') a11 += 1; 
		if(t[i] == '1' && s[i] == '0') a10 += 1;
		if(t[i] == '0' && s[i] == '1') a01 += 1;
		if(t[i] == '0' && s[i] == '0') a00 += 1;
	}
	printf("%lld\n", a00 * a11 + a01 * a10 + a00 * a01);
}