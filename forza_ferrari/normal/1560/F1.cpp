#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int t,k,n,ans[21],cnt[21];
string s;
bool dfs(int now,int val,bool tag)
{
    if(val>k)
        return 0;
    if(now==n&&val<=k)
    {
        for(register int i=0;i<n;++i)
            cout<<ans[i];
        cout<<endl;
        return 1;
    }
    for(register int i=tag? s[now]-'0':0;i<=9;++i)
    {
        ++cnt[i];
        ans[now]=i;
        if(cnt[i]==1)
        {
            if(dfs(now+1,val+1,tag&&i==s[now]-'0'))
                return 1;
        }
        else
            if(dfs(now+1,val,tag&&i==s[now]-'0'))
                return 1;
        --cnt[i];
    }
    return 0;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        for(register int i=0;i<=10;++i)
            cnt[i]=0;
        for(register int i=0;i<=10;++i)
            ans[i]=0;
        cin>>s>>k;
        n=s.length();
        if(!dfs(0,0,1))
        {
            cout<<10;
            for(register int i=2;i<k;++i)
                cout<<i;
            cout<<endl;
        }
    }
    return 0;
}