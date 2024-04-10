#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
char s[105];
int n;
void Solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int st=0;
	for(int i=1;i<=n;++i)	if(s[i]!=s[i-1])	++st;
	if(st&1)
	{
		puts(s+1);
		return ;
	}
	if(s[1]=='a')	s[1]='b';
	else	s[1]='a';
	puts(s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}