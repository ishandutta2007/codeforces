#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,ans;
priority_queue<int> q;
signed main()
{
    cin>>n;
    for(register int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        x-=i;
        q.push(x);
        int y=q.top();
        if(y>x)
        {
            q.pop();
            q.push(x);
            ans+=y-x;
        }
    }
    cout<<ans<<endl;
    return 0;
}