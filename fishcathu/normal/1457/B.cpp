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
int a[N];
vector<int>v[101];
int f(int m,int k)
{
	if(m<0)return 0;
	int ans=m/k;
	if(m%k)++ans;
	return ans;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),k=read(),m=100,ans=1<<30;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=m;++i)
		{
			int s=0;
			for(int j=1;j<=n;++j)
			{
				if(a[j]!=i)++s,j+=k-1;
			}
			if(s<ans)ans=s;
		}
		printf("%d\n",ans);
	}
}