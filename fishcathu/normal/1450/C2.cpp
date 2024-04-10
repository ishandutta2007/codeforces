#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
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
char a[310][310];int O[3],X[3];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read(),s=0;
 		for(int i=0;i<3;++i)O[i]=X[i]=0;
		for(int i=1;i<=n;++i)scanf("%s",*(a+i)+1);
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		{
			int t=(i+j)%3;
			if(a[i][j]=='O')++O[t],++s;
			else if(a[i][j]=='X')++X[t],++s;
		}
		s/=3;
		int l=0,r;
		while(1)
		{
			for(r=0;r<3;++r)
			{
				if(r==l)continue;
				if(O[l]+X[r]<=s)break;
			}
			if(r<3)break;
			++l;
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		{
			int t=(i+j)%3;
			if(t==l&&a[i][j]=='O')a[i][j]='X';
			else if(t==r&&a[i][j]=='X')a[i][j]='O';
		}
		for(int i=1;i<=n;++i)puts(*(a+i)+1); 
	}
}