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
const int N=8E5+10;
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
    vector<pii>a(read());
    for(auto &[x,y]:a)x=(y=read())+read();
    sort(a.begin(),a.end());
    priority_queue<int>ql;
    priority_queue<int,vct,greater<int>>qr;
    ql.push(0);
    qr.push(0);
    ll ans=0;
    for(auto [x,y]:a)
    {
        int z=y-x;
        if(y<ql.top())
        {
            ql.push(y);
            ql.push(y);
            qr.push(ql.top()-x);
            ans+=ql.top()-y;
            ql.pop();
        }
        else
        {
            qr.push(z);
            qr.push(z);
            ql.push(qr.top()+x);
            ans+=z-qr.top();
            qr.pop();
        }
    }
    write(ans,'\n');
}