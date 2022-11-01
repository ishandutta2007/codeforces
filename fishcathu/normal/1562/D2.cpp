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
const int N=3E5+10;
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
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        char c;
        do c=getchar();while(c<43);
        if(i&1^c==43)a[i]=a[i-1]-1;
        else a[i]=a[i-1]+1;
    }
    while(m--)
    {
        int l=read()-1,r=read();
        if(a[r]==a[l])puts("0");
        else
        {
            if(r-l&1)puts("1");
            else puts("2"),write(++l,' ');
            int y=a[l]+a[r],u=l+1;
            bool b=a[l]<a[r];
            for(int v=r;u^v;)
            {
                int mid=u+v>>1,z=a[mid]+a[mid-1];
                z==y||z<y^b?v=mid:u=mid+1;
            }
            write(u,'\n');
        }
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}