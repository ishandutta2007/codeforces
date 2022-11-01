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
const int N=1E6+10;
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
map<pii,bool>f;
int a[2][N][2],b[2][3],c[2],g[N];
void add(int i,int j,int k,int w)
{
    --b[i][!a[i][j][0]+!a[i][j][1]];
    a[i][j][k]+=w;
    ++b[i][!a[i][j][0]+!a[i][j][1]];
}
int main()
{
    const int p=998244353;
    g[0]=1;
    for(int i=1;i<N;++i)g[i]=g[i-1]*2%p;
    b[0][2]=read(),b[1][2]=read();
    for(int s=read();s--;)
    {
        int x=read(),y=read(),k=read();
        map<pii,bool>::iterator it=f.find({x,y});
        if(it!=f.end())
        {
            add(0,x,y+it->se&1,-1);
            add(1,y,x+it->se&1,-1);
            --c[x+y+it->se&1];
            f.erase(it);
        }
        if(~k)
        {
            add(0,x,y+k&1,1);
            add(1,y,x+k&1,1);
            ++c[x+y+k&1];
            f[{x,y}]=k;
        }
        int res=-!c[0]-!c[1];
        if(!b[0][0])res+=g[b[0][2]];
        if(!b[1][0])res+=g[b[1][2]];
        write(res%p,'\n');
    }
}