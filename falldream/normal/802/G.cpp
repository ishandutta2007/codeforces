#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

char s[]="heidi",st[100005];
int n,num=0;

int main()
{
	scanf("%s",st+1);
	for(int i=1;st[i];++i)
	{
		if(st[i]==s[num]) ++num;
		if(num==5) return 0*puts("YES");	
	}
	puts("NO");
	return 0;
}