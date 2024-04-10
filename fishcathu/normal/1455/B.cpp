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
    char a[19],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}

int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		int i=0,s=0;
		while(1)
		{
			++i;
			s+=i;
			if(s>=n)break;
		}
		if(s==n)printf("%d\n",i);
		else if(s==n+1)printf("%d\n",i+1);
		else printf("%d\n",i);
	}
}