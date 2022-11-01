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
int a[N],l[N],r[N],v[N],mx[N];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read();
 		for(int i=1;i<=n;++i)a[i]=read(),mx[i]=0;
 		a[n+1]=0;
 		for(int i=1,s=0;i<=n+1;++i)
 		{
 			while(s&&a[v[s]]>a[i])r[v[s--]]=i;
 			v[++s]=i;
		}
		for(int i=n,s=0;i>=0;--i)
 		{
 			while(s&&a[v[s]]>a[i])l[v[s--]]=i;
 			v[++s]=i;
		}
		for(int i=1;i<=n;++i)mx[a[i]]=max(mx[a[i]],r[i]-l[i]-1);
		for(int i=2;i<=n;++i)mx[i]=min(mx[i],mx[i-1]);
		for(int i=n;i>=1;--i)write(mx[i]>n-i);
		putchar('\n');
	}
	return 0;
}