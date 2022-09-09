#include<ctype.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long LL;
#define maxn 1200
char s[maxn];
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%s", s);
		int n = strlen(s), flag = 1;
		for(int i = 1; i < n && flag; i += 1)
			if(s[i] != s[0]){
				flag = 0;
				char t = s[i];
				s[i] = s[n - 1];
				s[n - 1] = t;
				puts(s);
			}
		if(flag) puts("-1");
	}
}