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
char a[2010][2010];int l[10],r[10],u[10],d[10],ans[10];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read();
 		for(int i=1;i<=n;++i)scanf("%s",*(a+i)+1);
 		for(int i=0;i<=9;++i)l[i]=u[i]=n,r[i]=d[i]=1,ans[i]=0;
 		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
 		{
 			int t=a[i][j]&15;
			l[t]=min(l[t],j);
			r[t]=max(r[t],j);
			u[t]=min(u[t],i);
			d[t]=max(d[t],i);
		}
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		{
			int t=a[i][j]&15;
			int p=max(i-1,n-i);
			int q=max(j-l[t],r[t]-j);
			ans[t]=max(ans[t],p*q);
			p=max(j-1,n-j);
			q=max(i-u[t],d[t]-i);
			ans[t]=max(ans[t],p*q);
		}
		for(int i=0;i<=9;++i)
		{
			if(l[i]>=r[i]&&u[i]>=d[i])putchar('0');
			else write(ans[i]);
			putchar(i==9?'\n':' ');
		}
	}
}