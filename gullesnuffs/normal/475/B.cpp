#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[25][25];

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < 2; ++i)
		scanf("%s", s[i]);
	bool ok=1;
	if(s[0][0] == s[0][n-1] || s[1][0] == s[1][m-1])
		ok=0;
	if((s[0][0] == '<') != (s[1][0] == 'v'))
		ok=0;
	puts(ok?"YES":"NO");
}