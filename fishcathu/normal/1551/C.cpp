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
const int N=2E5+10;
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
int a[26][N];
void solve()
{
    int n=read();
    for(int j=0;j<n;++j)
    {
        for(int i=0;i<26;++i)a[i][j]=0;
        int s=0;
        char c;
        do c=getchar();while(c<97);
        do ++a[c-97][j],++s;while((c=getchar())>96);
        for(int i=0;i<26;++i)a[i][j]=a[i][j]*2-s;
    }
    int ans=0;
    for(int i=0;i<26;++i)
    {
        sort(a[i],a[i]+n,greater<int>());
        int j=0;
        for(int s=0;j<n;++j)
        {
            s+=a[i][j];
            if(s<=0)break;
        }
        ans=max(ans,j);
    }
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}