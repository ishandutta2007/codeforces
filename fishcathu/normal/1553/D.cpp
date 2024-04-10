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
const int N=1E5+10;
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
char a[N],b[N];
void solve()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1),res=0;
    bool k=n+m&1;
    for(int i=1;i<=n;++i)
    {
        if(i+k&1&&a[i]==b[res+1])
        {
            ++res;
            k^=1;
        }
    }
    puts(res==m?"YES":"NO");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}