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
const int N=2.5E5+10;
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
int a[N],n,m,b[N>>1];
int c[13][2][2],d[13],s;
int v[5][2];
bool check(int x)
{
    for(int i=d[x];i--;)b[c[x][i][0]]=c[x][i][1];
    int i=1;
    for(int w=m;i<n;++i)
    {
        int cnt=0;
        for(int j=0;j<m;++j,++w)
        {
            if(a[w]==b[j])continue;
            if(++cnt==5)break;
            v[cnt][0]=j;
            v[cnt][1]=a[w];
        }
        if(cnt<=2)continue;
        if(d[x]+cnt>4)break;
        if(cnt==3)
        {
            for(int j=1;j<=3;++j)
            {
                ++s;
                d[s]=d[x];
                for(int k=d[x];k--;)
                {
                    c[s][k][0]=c[x][k][0];
                    c[s][k][1]=c[x][k][1];
                }
                c[s][d[s]][0]=v[j][0];
                c[s][d[s]][1]=v[j][1];
                ++d[s];
            }
        }
        else
        {
            for(int j=1;j<4;++j)for(int k=j+1;k<=4;++k)
            {
                ++s;
                d[s]=d[x];
                for(int y=d[x];y--;)
                {
                    c[s][y][0]=c[x][y][0];
                    c[s][y][1]=c[x][y][1];
                }   
                c[s][d[s]][0]=v[j][0];
                c[s][d[s]][1]=v[j][1];
                ++d[s];
                c[s][d[s]][0]=v[k][0];
                c[s][d[s]][1]=v[k][1];
                ++d[s];
            }
        }
        break;
    }
    if(i==n)return 1;
    for(i=d[x];i--;)b[c[x][i][0]]=a[c[x][i][0]];
    return 0;
}
int main()
{
    n=read();
    m=read();
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)a[i*m+j]=read();
    memcpy(b,a,m<<2);
    for(int i=0;i<=s;++i)
    {
        if(check(i))
        {
            puts("Yes");
            for(int j=0;j<m;++j)write(b[j],' ');
            return 0;
        }
    }
    puts("No");
}