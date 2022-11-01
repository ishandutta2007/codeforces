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
struct st
{
    ll val;
    string l;
    string r;
    st(ll x=0,string y="",string z="")
    {
        val=x;
        l=y.substr(0,3);
        r=z.substr(max((int)z.size()-3,0),3);
    }
};
map<string,st>f;
string readd()
{
    string x;
    cin>>x;
    return x;
}
int cnt(string x)
{
    int res=0;
    for(int i=x.size()-4;i>=0;--i)
    {
        if(x.substr(i,4)=="haha")
        {
            ++res;
        }
    }
    return res;
}
void solve()
{
    f.clear();
    int n;
    cin>>n;
    while(n--)
    {
        string a=readd();
        if(readd()==":=")
        {
            string b=readd();
            f[a]=st(cnt(b),b,b);
        }
        else
        {
            st u=f[readd()];
            readd();
            st v=f[readd()];
            f[a]=st(u.val+v.val+cnt(u.r+v.l),u.l+v.l,u.r+v.r);
        }
        if(!n)write(f[a].val,'\n');
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}