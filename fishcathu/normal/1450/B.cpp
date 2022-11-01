#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int l[N],r[N];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read(),m=read();
 		for(int i=1;i<=n;++i)l[i]=read(),r[i]=read();
 		int i=1;
 		while(i<=n)
 		{
 			int j=1;
 			while(j<=n)
 			{
 				if(abs(l[j]-l[i])+abs(r[j]-r[i])>m)break;
 				++j;
			}
			if(j>n)break;
 			++i;
		}
		puts(i>n?"-1":"1");
	}
}