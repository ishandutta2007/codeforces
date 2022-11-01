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
const int N=2E5+10;
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
int a[N],b[N];
vector<int>ans;
void modify(int x){a[x]=a[x+1]=a[x+2]=a[x]^a[x+1]^a[x+2],ans.pb(x);}
void solve()
{
    int n=read(),m=0;
    for(int i=1;i<=n;++i)if(a[i]=read())b[++m]=i;
    if(m&1){puts("NO");return;}
    ans.clear();
    for(int i=1;i<m;i+=2)
    {
        for(int j=b[i];j<b[i+1]-2;j+=2)modify(j);
        if(!a[b[i+1]-1])modify(b[i+1]-2);
    }
    int w=0;
    for(int i=1;i<=n;++i)if(!a[i])w=i;
    if(!w){puts("NO");return;}
    for(int i=w;i<n;++i)if(a[i+1])modify(i);
    for(int i=w;i>1;--i)if(a[i-1])modify(i-2);
    puts("YES");
    write(ans.size(),'\n');
    for(int x:ans)write(x,' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}