#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E5+10;
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
int a[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int w=min_element(a+1,a+1+n)-a;
    write(n-1,'\n');
    for(int i=w;--i>=1;)printf("%d %d %d %d\n",i,w,a[w]+w-i,a[w]);
    for(int i=w;++i<=n;)printf("%d %d %d %d\n",w,i,a[w],a[w]+i-w);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}