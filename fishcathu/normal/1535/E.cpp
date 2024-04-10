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
const int N=3E5+10,M=19;
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
int a[N],b[N],fa[N][M];
int main()
{
    int n=read()+1;
    a[1]=read(),b[1]=read();
    for(int i=2;i<=n;++i)
    {
        int op=read(),u=read()+1;
        if(op==1)
        {
            a[i]=read(),b[i]=read();
            fa[i][0]=u;
            for(int j=1;j<M;++j)fa[i][j]=fa[fa[i][j-1]][j-1];
        }
        else
        {
            int s=read(),ans0=0;
            ll ans1=0;
            while(s&&a[u])
            {
                int v=u;
                for(int j=M;j--;)
                {
                    if(a[fa[v][j]])
                    {
                        v=fa[v][j];
                    }
                }
                int t=min(s,a[v]);
                s-=t;
                a[v]-=t;
                ans0+=t;
                ans1+=t*1LL*b[v];
            }
            write(ans0,' ');
            write(ans1,'\n');
            fflush(stdout);
        }
    }
}