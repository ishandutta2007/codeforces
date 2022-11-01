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
const int N=1<<24;
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
int a[N];
char c[4];
int main()
{
    int n=read();
    for(int i=n;i--;)
    {
        scanf("%s",c);
        int res=0;
        for(int j=0;j<3;++j)res|=1<<c[j]-97;
        ++a[res];
    }
    for(int i=2,j=1;i<=N;i<<=1,j<<=1)
    {
        for(int x=0;x<N;x+=i)
        {
            for(int y=0;y<j;++y)
            {
                a[x+y+j]+=a[x+y];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<N;++i)
    {
        int t=n-a[i];
        ans^=t*1LL*t;
    }
    write(ans,'\n');
}