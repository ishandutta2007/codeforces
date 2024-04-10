#include<bits/stdc++.h>
using namespace std;
char s[100005],t[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s %s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int pos1=n,pos2=m;
		while(1)
		{
			if(s[pos1]==t[pos2])	--pos1,--pos2;
			else	pos1-=2;
			if(!pos2 || pos1<=0)	break;
		}
		puts(pos2?"NO":"YES");
	}
	return 0;
}