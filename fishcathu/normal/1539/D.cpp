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

int main()
{
    ll s=0;
    vector<pair<ll,ll>>a(read());
    for(auto &[x,y]:a)s+=y=read(),x=read()+1;
    sort(a.begin(),a.end());
    ll w=1,ans=s<<1;
    for(auto [x,y]:a)
    {
        ll l=min(max(x,w),s+1);
        w=min(l+y,s+1);
        ans-=w-l;
    }
    write(ans,'\n');
}