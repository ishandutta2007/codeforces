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
const int N=2E5+1,M=17985;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int pri[M],pre[N],rev[N];
int n,ans=1;
map<int,int>ma[N];
vector<int>v[M];
const int p=1E9+7;
void add(int x,int val)
{
    while(val!=1)
    {
        int t=pre[val];
        val/=t;
        t=rev[t];
        int y=ma[x][t]++;
        if(y==v[t].size())v[t].pb(0);
        if(++v[t][y]==n)
        {
            ans=ans*1ll*pri[t]%p;
        }
    }
}
int main()
{
    for(int i=2,s=0;i<N;++i)
    {
        if(!pre[i])
        {
            pri[++s]=pre[i]=i;
            rev[i]=s;
        }
        for(int j=1;j<=s&&i*pri[j]<N;++j)
        {
            pre[i*pri[j]]=pri[j];
            if(!(i%pri[j]))break;
        }
    }
    n=read();
    int m=read();
    for(int i=1;i<=n;++i)add(i,read());
    while(m--)
    {
        int w=read();
        add(w,read());
        write(ans,'\n');
    }
}