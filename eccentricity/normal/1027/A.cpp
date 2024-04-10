#include<bits/stdc++.h>
#define maxn 120
using namespace std;
typedef long long LL;
char s[maxn];
int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t += 1){
		int n;
		scanf("%d %s", &n, s);
		bool flag = true;
		for(int i = 0; i < n; i += 1)
			if(s[i] != s[n - 1 - i] && abs(s[i] - s[n - 1 - i]) != 2)
				flag = false;
		printf(flag ? "YES\n" : "NO\n");
	}
}