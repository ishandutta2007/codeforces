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
int a[N];
int main()
{
	a[0]=-1;
	for(int x=read();x--;)
	{
		int n=read(),m=read(),k,b=0,ans=0,mmm=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)
		{
			if(a[i]>m&&!b)b=1,k=i;
			if(a[i]<a[i-1])
			{
				if(!b||a[i]<a[i-2]||a[i]<m){mmm=1;break;}
				m=a[i-1];
				b=0;
				for(int j=k;j<i;++j)if(a[j]!=a[j-1])++ans;
			}
		}
		if(mmm)puts("-1");
		else printf("%d\n",ans);
	}
}