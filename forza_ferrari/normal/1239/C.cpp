#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
struct element
{
    int pos,t;
    bool operator <(const element &other) const
    {
        return t^other.t? t<other.t:pos<other.pos;
    }
}a[100001];
int n,m,t,ans[100001],p;
queue<int> q;
set<int> s;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].t;
        a[i].pos=i;
    }
    sort(a+1,a+n+1);
    p=1;
    while(p<=n)
    {
        t=a[p].t;
        q.push(a[p].pos);
        ++p;
        while(!q.empty())
        {
            t+=m;
            while(p<=n&&a[p].t<=t)
            {
                if(q.empty()||q.back()>a[p].pos)
                    q.push(a[p].pos);
                else
                    s.insert(a[p].pos);
                ++p;
            }
            ans[q.front()]=t;
            q.pop();
            if(q.empty()&&!s.empty())
            {
                q.push(*s.begin());
                s.erase(s.begin());
            }
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}