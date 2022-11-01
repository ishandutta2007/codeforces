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
int a[N],b[N],c[N];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read(),ans=0;
 		for(int i=1;i<=n;++i)a[i]=read(),b[i]=c[i]=0;
 		for(int i=1;i<=n;++i)++b[a[i]];
 		if(*max_element(b+1,b+1+n)>n+1>>1)
 		{
 			puts("-1");
 			continue;
		}
 		for(int i=2;i<=n;++i)if(a[i]==a[i-1])
		{
		 	++ans;
			++c[a[i]];
			++c[a[i-1]];
		}
 		++c[a[1]];
		++c[a[n]];
 		printf("%d\n",max(ans,*max_element(c+1,c+1+n)-2));
	}
}