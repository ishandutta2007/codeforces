#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1E6+10;
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
char a[510],m;
char f(char c)
{
	if(c==97||c==m)return 97;
	return c-1;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		m=read()+96;
		scanf("%s",a+1);
		for(int i=1,j=1;i<=n;++i)
		{
			char k=0,mn=a[i];
			if(j&&f(a[i])<mn)mn=f(a[i]),k=1;
			if(i<n&&a[i+1]<mn)mn=a[i+1],k=2;
			if(j&&i<n&&f(a[i+1])<mn)mn=f(a[i+1]),k=3;
			if(i<n-1&&a[i+2]<mn)mn=a[i+2],k=4;
			if(k==2)a[i+1]=j?f(a[i]):a[i];
			else if(k==3)a[i+1]=a[i];
			else if(k==4)a[i+2]=a[i+1],a[i+1]=j?f(a[i]):a[i];
			a[i]=mn;
			j=k<=1;
			if(k==4)++i;
		}
		puts(a+1);
	}
}