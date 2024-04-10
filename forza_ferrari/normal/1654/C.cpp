#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define int long long
int t,n,sum;
multiset<int> s;
inline bool dfs(int k)
{
    if(s.find(k)!=s.end())
    {
        s.erase(s.find(k));
        return 1;
    }
    if(k<2)
        return 0;
    return dfs(k>>1)&&dfs(k-(k>>1));
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        s.clear();
        sum=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            sum+=x;
            s.insert(x);
        }
        if(dfs(sum)&&s.empty())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}