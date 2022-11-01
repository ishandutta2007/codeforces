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
const int N=510;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
vector<pii>q={{-1,0},{1,0},{0,-1},{0,1}};
char a[N][N];
int ans[N][N];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(int i=1,k=0;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]=='X')
            {
                bool op=0;
                for(auto [x,y]:q)op^=a[i+x][j+y]=='.';
                if(op){puts("NO");return 0;}
                k^=a[i-1][j]=='X';
            }
            else ans[i][j]=j&1^k?1:4;
        }
    }
    puts("YES");
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]=='X')
            {
                int res=0;
                for(auto [x,y]:q)res+=ans[i+x][j+y];
                write(res,' ');
            }
            else write(ans[i][j],' ');
        }
        putchar('\n');
    }
}