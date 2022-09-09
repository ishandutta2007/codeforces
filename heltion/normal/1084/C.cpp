#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
#define maxn 120000
char s[maxn];
int main(){
	scanf("%s", s);
	int n = strlen(s);
	LL a = 1, k = 0;
	for(int i = 0; i < n; i += 1){
		if(s[i] == 'a') k += 1;
		if(s[i] == 'b'){
			a = a * (k + 1) % mod;
			k = 0;
		}
	}
	a = a * (k + 1) % mod;
	printf("%lld", a - 1);
}