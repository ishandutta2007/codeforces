#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int t,n,a[200001],b[200001];
priority_queue<int> q1,q2;
inline int read()
{
    int x=0;
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
int main()
{
    t=read();
    while(t--)
    {
        int ans=0;
        n=read();
        for(int i=1;i<=n;++i)
        {
            a[i]=read();
            q1.emplace(a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            b[i]=read();
            q2.emplace(b[i]);
        }
        while(!q1.empty()&&!q2.empty())
        {
            if(q1.top()==q2.top())
            {
                q1.pop();
                q2.pop();
                continue;
            }
            ++ans;
            if(q1.top()>q2.top())
            {
                int k=q1.top();
                q1.pop();
                int cnt=1,val=10;
                while(k>=val)
                {
                    val*=10;
                    ++cnt;
                }
                q1.emplace(cnt);
            }
            else
            {
                int k=q2.top();
                q2.pop();
                int cnt=1,val=10;
                while(k>=val)
                {
                    val*=10;
                    ++cnt;
                }
                q2.emplace(cnt);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}