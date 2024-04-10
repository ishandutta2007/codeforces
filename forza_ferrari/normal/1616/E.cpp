#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;
#define int long long
int t,n,ans,sum[200001];
string a,b;
set<int> s[26];
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x)
{
    for(;x<=n;x+=lowbit(x))
        ++sum[x];
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        a=" "+a;
        b=" "+b;
        for(int i=0;i<26;++i)
            s[i].clear();
        for(int i=1;i<=n;++i)
        {
            s[a[i]-'a'].emplace(i);
            sum[i]=0;
        }
        int cnt=0;
        ans=1e18;
        for(int i=1;i<=n;++i)
        {
            int pos=1e18;
            for(int j=0;j<b[i]-'a';++j)
                if(!s[j].empty())
                    pos=min(pos,*s[j].begin());
            if(pos<1e18)
                ans=min(ans,cnt+pos-i+query(n)-query(pos-1));
            if(s[b[i]-'a'].empty())
                break;
            pos=*s[b[i]-'a'].begin();
            cnt+=pos-i+query(n)-query(pos-1);
            update(pos);
            s[b[i]-'a'].erase(pos);
        }
        cout<<(ans<1e18? ans:-1)<<'\n';
    }
    return 0;
}