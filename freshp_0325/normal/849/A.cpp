/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
int n,a[105];
int main(){
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	if(n%2==0)	return puts("No")&0;
	if(a[1]%2==0 || a[n]%2==0)	return puts("No")&0;\
	puts("Yes");
	return 0;
}