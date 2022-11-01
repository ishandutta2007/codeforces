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
struct st
{
    int w,id;
    bool b;
    bool operator<(const st m)const
    {
        return w<m.w;
    }
}a[N];
int q[2][N],ans[N];
void solve()
{
    int n=read(),m=read()<<1;
    for(int i=1;i<=n;++i)
    {
        a[i].w=read();
        a[i].id=i;
        ans[i]=-1;
    }
    for(int i=1;i<=n;++i)
    {
        char t;
        do t=getchar();while(t!='L'&&t!='R');
        a[i].b=t=='R';
    }
    sort(a+1,a+1+n);
    int s[2]={0};
    for(int i=1;i<=n;++i)
    {
        bool k=a[i].w&1;
        if(!s[k]||a[i].b)q[k][++s[k]]=i;
        else
        {
            int j=q[k][s[k]--];
            ans[a[i].id]=ans[a[j].id]=a[i].w-(a[j].b?a[j].w:-a[j].w)>>1;
        }
    }
    for(int k=0;k<=1;++k)
    {
        while(s[k]>1)
        {
            int i=q[k][s[k]--],j=q[k][s[k]--];
            ans[a[i].id]=ans[a[j].id]=m-a[i].w-(a[j].b?a[j].w:-a[j].w)>>1;
        }
    }
    for(int i=1;i<=n;++i)write(ans[i],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}