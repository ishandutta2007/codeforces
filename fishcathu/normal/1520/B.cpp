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
typedef pair<ll,ll> pll;
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

void solve()
{
    string a;
    cin>>a;
    for(char &x:a)x-=48;
    int ans=(a.size()-1)*9+a[0];
    for(char x:a)
    {
        if(x!=a[0])
        {
            if(x<a[0])--ans;
            break;
        }
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