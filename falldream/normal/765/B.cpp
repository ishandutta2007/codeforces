#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
bool b[100];
char s[5005];

int main()
{
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
	{
		int to=s[i]-'a';
		for(int j=1;j<=to;j++) if(!b[j]) return puts("NO")*0;
		b[s[i]-'a'+1]=1;	
	}		
	puts("YES");
	return 0;
}