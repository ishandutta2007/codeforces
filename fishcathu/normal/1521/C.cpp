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
const int N=1E4+10;
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
int ask(int op,int l,int r,int x)
{
    printf("? %d %d %d %d\n",op,l,r,x);
    fflush(stdout);
    return read();
}
void solve()
{
    int n=read(),w;
    for(int i=1;i<=n;)
    {
        int k=ask(2,i,i+1,1);
        if(k==1)
        {
            w=i;
            break;
        }
        else if(k==2&&ask(2,i+1,i,1)==1)
        {
            w=i+1;
            break;
        }
        i+=2;
        if(i==n)--i;
    }
    for(int i=1;i<=n;++i)
    {
        if(i==w)a[i]=1;
        else a[i]=ask(1,w,i,n-1);
    }
    printf("! ");
    for(int i=1;i<=n;++i)write(a[i],' ');
    putchar('\n');
    fflush(stdout);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}