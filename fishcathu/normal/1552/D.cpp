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
const int N=20;
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
bool solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=pow(3,n);--i;)
    {
        int res=0;
        for(int j=1,k=i;k;++j,k/=3)
        {
            if(k%3==1)res+=a[j];
            else if(k%3==2)res-=a[j];
        }
        if(!res)return 1;
    }
    return 0;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}