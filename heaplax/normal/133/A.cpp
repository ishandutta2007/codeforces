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
char s;
bool ok;
int main()
{
	while(scanf("%c",&s)==1)
		if(s=='H' || s=='Q' || s=='9')ok=true;
	if(ok)printf("YES");
	else printf("NO");
	return 0;
}