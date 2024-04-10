#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[210],c[10]=" 2020";
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		scanf("%s",a+1);
		int l=1,r=0;
		while(a[l]==c[l])++l;
		while(a[n-r]==c[4-r])++r;
		puts(l+r>4?"YES":"NO");
	}
}