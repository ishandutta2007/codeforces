#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
char s[maxn];
int main(){
	int n;
	scanf("%d %s", &n, s);
	for(int i = 0; i + 1 < n; i += 1)
		if(s[i] != s[i + 1]){
			printf("YES\n%c%c", s[i], s[i + 1]);
			return 0;
		}
	printf("NO");
}