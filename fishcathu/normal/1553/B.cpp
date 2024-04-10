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
const int N=510;
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
char a[N],b[N<<1];
bool solve()
{
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int k=1;
            while(k<=m)
            {
                int t=i-abs(j-k);
                if(t<1||a[t]!=b[k])break;
                ++k;
            }
            if(k>m)return 1;
        }
    }
    return 0;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}