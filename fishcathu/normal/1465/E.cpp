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
char a[N];
int main()
{
	int n=read();
	ll m;
	scanf("%lld%s",&m,a+1);
	for(int i=1;i<=n;++i)a[i]-=97;
	sort(a+1,a-1+n);
	m+=(1<<a[n-1])-(1<<a[n]);
	for(int i=n-2;i>=1;--i)
	{
		int t=1<<a[i];
		m>0?m-=t:m+=t;
	}
	puts(m?"No":"Yes");
}