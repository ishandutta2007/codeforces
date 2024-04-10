#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
int n,a[101];
string s[101];
set<int> ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    queue<int> q;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!a[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        ans.insert(k);
        for(int i=1;i<=n;++i)
            if(s[k][i]=='1')
                if(!--a[i])
                    q.push(i);
    }
    for(int i=1;i<=n;++i)
        if(!a[i])
        {
            puts("-1");
            return 0;
        }
    cout<<ans.size()<<'\n';
    for(int i:ans)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}