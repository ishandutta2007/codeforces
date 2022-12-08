#include<bits/stdc++.h>
using namespace std;
char s[300010];
int main() {
	int n,fl=1,x,y;
	scanf("%d%s",&n,s);
	for(int i=1;i<n&&fl;i++)
		if(s[i]<s[i-1])fl=0,x=i-1,y=i;
	puts(fl?"NO":"YES");
	if(!fl)printf("%d %d\n",x+1,y+1);
	return 0;
}