#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=17;
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
typedef bitset<N> bt;
int n,m,ans=inf;
bt b[N];
void solve(string a,bt c)
{
    ans=min(ans,(int)a.size());
    for(int i=0;i<m;++i)
    {
        if(!c[i])continue;
        string t;
        bool op=0;
        for(char x:a)
        {
            if(x==i)continue;
            if(!t.empty()&&!b[t.back()][x])
            {
                op=1;
                break;
            }
            t+=x;
        }
        if(op)continue;
        c[i]=0;
        solve(t,c);
        return;
    }
}
int main()
{
    n=read(),m=read();
    string a;
    cin>>a;
    for(char &x:a)x-=97;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)
        {
            b[i][j]=read();
        }
    }
    solve(a,(1<<m)-1);
    write(ans,'\n');
}