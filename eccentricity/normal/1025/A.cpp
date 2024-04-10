#include<bits/stdc++.h>
#define maxn 120000 
using namespace std;
char s[maxn];
int c[26];
int main(){
	int n;
	scanf("%d %s", &n, s);
	bool flag = n == 1;
	for(int i = 0; i < n; i += 1){
		c[s[i] - 'a'] += 1;
	}
	for(int i = 0; i < 26; i += 1)
		if(c[i] >= 2) flag = true;
	printf(flag ? "Yes" : "No");
}