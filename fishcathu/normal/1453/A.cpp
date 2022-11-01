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
int a[105];
int main()
{
 	for(int x=read();x--;)
 	{
 		memset(a,0,sizeof a);
		int n=read(),m=read(),ans=0;
		for(int i=n;i--;)a[read()]=1;
		for(int i=m;i--;)if(a[read()])++ans;
		printf("%d\n",ans);	
	}
}