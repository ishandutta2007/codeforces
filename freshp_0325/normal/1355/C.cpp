#include<bits/stdc++.h>
#define Sunset namespace
#define Toybox std
using Sunset Toybox;
typedef long long LL;
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL A,B,C,D;
LL Sum(LL x){return x*(x+1)/2;}
int main(){
	A=read(),B=read(),C=read(),D=read();
	LL ans=0;
	for(LL i=max(C+1,A+B);i<=B+C;++i)	ans+=(min(D+1,i)-C)*(min(i-B,B)-max(i-C,A)+1);
	write(ans);
	return 0;
}