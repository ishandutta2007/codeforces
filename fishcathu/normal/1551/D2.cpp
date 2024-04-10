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
bool a[N][N];
bool solve()
{
    int n=read(),m=read(),k=read();
    if(n&1)
    {
        k=n*m/2-k;
        if(k>n/2*m||k&1)return 0;
        memset(a,0,sizeof a);
        for(int i=0;k;i+=2)
        {
            for(int j=0;j<m&&k;++j,--k)
            {
                a[i][j]=a[i+1][j]=1;
            }
        }
    }
    else
    {
        if(k>m/2*n||k&1)return 0;
        memset(a,1,sizeof a);
        for(int j=0;k;j+=2)
        {
            for(int i=0;i<n&&k;++i,--k)
            {
                a[i][j]=a[i][j+1]=0;
            }
        }
    }
    puts("YES");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]&1)putchar(97+(i/2+j&1));
            else putchar(99+(j/2+i&1));
        }
        putchar('\n');
    }
    return 1;
}
int main()
{
    for(int x=read();x--;)
    {
        if(!solve())puts("NO");
    }
}