#include<bits/stdc++.h>
#define maxn 240000 
using namespace std;
char s[maxn], t[maxn];
int main(){
	int n, m, p = -1;
	scanf("%d %d %s %s", &n, &m, s, t);
	for(int i = 0; i < n; i += 1) if(s[i] == '*') p = i;
	if(p == -1){
		if(n != m){
			printf("NO");
			return 0;
		}
		for(int i = 0; i < n; i += 1)
			if(s[i] != t[i]){
				printf("NO");
				return 0;
			}
		printf("YES");
		return 0;
	}
	if(n > m + 1){
		printf("NO");
		return 0;
	}
	bool flag = true;
	for(int i = 0; i < p; i += 1){
		if(s[i] != t[i]) flag = false;
	}
	for(int i = n - 1; i > p; i -= 1)
		if(s[i] != t[m - (n - i)]) flag = false;
	printf(flag ? "YES" : "NO");
}