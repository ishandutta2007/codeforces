#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1510;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
string a[N];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=0;
	sort(a+1,a+1+n);
	const char y='S'^'E'^'T';
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			a[0]=a[i];
			for(int k=0;k<m;++k)
			{
				if(a[i][k]!=a[j][k])
				{
					a[0][k]^=a[j][k]^y;
				}
			}
			if(*lower_bound(a+1,a+1+n,a[0])==a[0])
			{
				++ans;
			}
		}
	}
	write(ans/3,'\n');
}