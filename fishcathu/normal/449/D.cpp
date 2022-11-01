#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1<<20;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N];
int main()
{
    const int p=1E9+7;
    a[0]=1;
    for(int i=1;i<N;++i)a[i]=a[i-1]*2%p;
    for(int n=read();n--;)++b[read()];
    for(int i=2,j=1;i<=N;i<<=1,j<<=1)
    {
        for(int x=0;x<N;x+=i)
        {
            for(int y=0;y<j;++y)
            {
                b[x+y]+=b[x+y+j];
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;++i)
    {
        int op=1;
        for(int j=i;j;j>>=1)
        {
            if(j&1)
            {
                op=p-op;
            }
        }
        ans=(ans+op*1LL*a[b[i]])%p;
    }
    write(ans,'\n');
}