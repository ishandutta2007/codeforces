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
const int N=1<<19;
const int inf=1<<25;
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
int ans[N],l[N],r[N];
int main()
{
    int m=read(),n=1<<read();
    for(int i=0;i<n;++i)ans[i]=l[i]=inf,r[i]=-inf;
    while(m--)
    {
        int x=read();
        l[x]=r[x]=0;
    }
    for(int i=1;i<n;i<<=1)
    {
        for(int j=0;j<n;j+=i<<1)
        {
            for(int k=0;k<i;++k)
            {
                int x=j+k,y=x+i;
                int t=min(ans[x],ans[y]);
                ans[x]=min(t,l[y]+i-r[x]);
                ans[y]=min(t,l[x]+i-r[y]);
                int u=l[x],v=l[y];
                l[x]=min(l[x],v+i);
                l[y]=min(l[y],u+i);
                u=r[x],v=r[y];
                r[x]=max(r[x],v+i);
                r[y]=max(r[y],u+i);
            }
        }
    }
    for(int i=0;i<n;++i)write(ans[i],' ');
}