#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
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
void solve()
{
	int n=read(),a[3]={0};
	for(int i=n;i--;)++a[read()%3];
	n/=3;
	int res=0;
	for(int i=0;i<=3;++i)
	{
		int j=i%3;
		int t=a[j]-n;
		if(t<=0)continue;
		a[j]-=t;
		a[(j+1)%3]+=t;
		res+=t;
	}
	write(res,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}