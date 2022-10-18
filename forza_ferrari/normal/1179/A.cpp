#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
long long n,q,maxn,cnt;
vector<long long> v;
deque<long long> dq;
vector<pair<long long,long long> > ans;
inline long long read()
{
    long long x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
void print(long long x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    n=read(),q=read();
    for(register int i=1;i<=n;++i)
    {
        long long x=read();
        dq.push_back(x);
        maxn=max(maxn,x);
    }
    ans.push_back(make_pair(0ll,0ll));
    while(dq.front()^maxn)
    {
        long long x=dq.front();
        dq.pop_front();
        long long y=dq.front();
        ans.push_back(make_pair(x,y));
        dq.pop_front();
        if(x<y)
            x^=y^=x^=y;
        dq.push_front(x);
        dq.push_back(y);
        ++cnt;
    }
    dq.pop_front();
    for(register int i=1;i<n;++i)
    {
        v.push_back(dq.front());
        dq.pop_front();
    }
    while(q--)
    {
        long long x=read();
        if(x<=cnt)
        {
            print(ans[x].first);
            putchar(' ');
            print(ans[x].second);
            puts("");
        }
        else
        {
            print(maxn);
            putchar(' ');
            print(v[(x-cnt-1)%(n-1)]);
            puts("");
        }
    }
    return 0;
}