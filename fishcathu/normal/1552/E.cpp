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
const int N=110;
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
int pre[N],l[N],r[N],b[N*N];
int main()
{
    int n=read(),m=read(),s=n*m,k=ceil(n/(m-1.0));
    for(int i=1;i<=s;++i)
    {
        int x=read();
        if(pre[x]&&!l[x])
        {
            int j=pre[x];
            while(j<=i&&b[j]<k)++j;
            if(j>i)
            {
                l[x]=pre[x];
                r[x]=i;
                for(j=pre[x];j<=i;++j)++b[j];
            }
        }
        pre[x]=i;
    }
    for(int i=1;i<=n;++i)printf("%d %d\n",l[i],r[i]);
}