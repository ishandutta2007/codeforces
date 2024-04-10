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
const int N=2E5+10;
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
set<int>q;
void solve()
{
    q.clear();
    int n=read(),l=read();
    q.insert(l);
    bool flag=0;
    while(--n)
    {
        int r=read();
        if(r==l)continue;
        set<int>::iterator it=q.find(l);
        if(r<l)
        {
            if(*q.begin()!=l&&*--it>r)
            {
               flag=1;
            }
        }
        else
        {
            if(*q.rbegin()!=l&&*++it<r)
            {
                flag=1;
            }
        }
        q.insert(r);
        l=r;
    }
    puts(flag?"NO":"YES");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}