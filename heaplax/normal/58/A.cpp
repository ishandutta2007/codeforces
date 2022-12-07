#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
char s[101];
int ans;
int main() {
	scanf("%s",&s);
	for(int i=0; i<strlen(s); i++)
		if((ans==0 && s[i]=='h')||(ans==1 && s[i]=='e')
		        || (ans==2 && s[i]=='l')||(ans==3 && s[i]=='l')||(ans==4 && s[i]=='o'))ans++;
	if(ans==5)printf("YES\n");
	else printf("NO\n");
	return 0;
}