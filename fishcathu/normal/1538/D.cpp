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
const int N=31630;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
bool b[N];
vector<int>q;
int f(int x)
{
    int res=0;
    for(int i:q)
    {
        if(i*i>x)break;
        while(!(x%i))
        {
            x/=i;
            ++res;
        }
    }
    if(x^1)++res;
    return res;
}
bool solve()
{
    int n=read(),m=read(),s=read(),k=0;
    if(n==m&&s==1)return 0;
    if(n^m)
    {
        if(n<m)swap(n,m);
        k=!!(n%m)+1;
    }
    return s>=k&&s<=f(n)+f(m);
}
int main()
{
    for(int i=2;i<N;++i)
    {
        if(!b[i])q.pb(i);
        for(int j:q)
        {
            int t=i*j;
            if(t>=N)break;
            b[t]=1;
            if(!(i%j))break;
        }
    }
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}