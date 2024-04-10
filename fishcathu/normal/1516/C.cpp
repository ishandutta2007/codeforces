#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+1;
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
bitset<N>b;
int a[101];
int main()
{
    int n=read(),s=0;
    b[0]=1;
    for(int i=1;i<=n;++i)
    {
        s+=a[i]=read();
        for(int j=s;j>=a[i];--j)
        {
            if(b[j-a[i]])
            {
                b[j]=1;
            }
        }
    }
    if(s&1||!b[s>>1])
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        int t=0;
        while(!(a[i]&1))
        {
            ++t;
            a[i]>>=1;
        }
        a[i]=t;
    }
    puts("1");
    write(min_element(a+1,a+1+n)-a,'\n');
}