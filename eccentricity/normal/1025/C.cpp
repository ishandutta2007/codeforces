#include<bits/stdc++.h>
#define maxn 160000 
using namespace std;
char s[maxn];
int main(){
	scanf("%s", s);
	int n = strlen(s);
	int p = 0, q = 0;
	int move = 0;
	int ans = 0;
	while(true){
		while(s[(q + 1) % n] != s[q] && (q + 1) % n != p){
			q = (q + 1) % n;
		}
		ans = max(ans, q - p < 0 ? q - p + n + 1: q - p + 1);
		move += q - p < 0 ? q - p + n + 1: q - p + 1;
		q = p = (q + 1) % n;
		if(move > 2 * n) break;
	}
	printf("%d", ans);
}