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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N],n;
priority_queue<int,vector<int>,greater<int>>q1;
priority_queue<int>q2;
void push(int x)
{
    while(x<=n)
    {
        ++b[x];
        x+=x&-x;
    }
}
int ask(int x)
{
    int res=0;
    while(x)
    {
        res+=b[x];
        x-=x&-x;
    }
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[read()]=i;
    ll ans=0;
    q2.push(0);
    for(int i=1,w=a[1];i<=n;++i)
    {
        int t=a[i];
        push(t);
        ans+=i-ask(t);
        if(t>w)
        {
            ans+=t-w+ask(w)-i;
        }
        else
        {
            ans+=w-t-ask(w)+1;
        }
        if(t>q2.top())q1.push(t);
        else q2.push(t);
        if(i&1)
        {
            int k=q1.size()-q2.size();
            if(k>0)
            {
                q2.push(q1.top());
                q1.pop();
            }
            else if(k<0)
            {
                q1.push(q2.top());
                q2.pop();
            }
            int y=q1.top();
            if(y!=w)
            {
                ans-=abs(w-y)-1;
            }
            w=y;
        }
        write(ans,' ');
    }
}