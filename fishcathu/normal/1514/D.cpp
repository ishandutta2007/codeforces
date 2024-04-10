#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+7;
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
int a[N],b[41],l,r;
vector<int>v[N];
int solve(int x)
{
    return upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
}
int main()
{
    b[1]=1;
    for(int i=2;i<=40;++i)b[i]=b[i-1]*2%N;
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        v[a[i]=read()].push_back(i);
    }
    while(m--)
    {
        l=read(),r=read();
        int s=r-l+1,mx=0;
        for(int i=40;i--;)
        {
            mx=max(mx,solve(a[l+b[i]%s]));
        }
        write(max(mx*2-s,1),'\n');
    }
}