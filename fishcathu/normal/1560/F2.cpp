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
const int N=60;
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
char a[N];
int f[N];
void solve()
{
    memset(f,0,sizeof f);
    int m=0;
    scanf("%s%d",a,&m);
    int n=strlen(a),i=0;
    set<char>q;
    for(int s=0;i<n;++i)
    {
        if(!f[a[i]]++)
        {
            if(++s>m)break;
            q.insert(a[i]);
        }
    }
    if(i^n)
    {
        set<char>::iterator it=q.lower_bound(a[i]);
        if(it!=q.end())a[i]=*it;
        else
        {
            while(--f[a[--i]]&&a[i]==*q.rbegin());
            if(f[a[i]])a[i]=*q.upper_bound(a[i]);
            else
            {
                q.erase(a[i]);
                if(a[i]=='9')--i;
                q.insert(++a[i]);
            }
        }
    }
    char t=q.size()<m?'0':*q.begin();
    while(++i<n)a[i]=t;
    puts(a);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}