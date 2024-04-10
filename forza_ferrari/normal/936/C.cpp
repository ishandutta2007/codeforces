#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int n,cnt[26];
string s,t,tmp;
vector<int> ans;
inline void shift(int x)
{
    tmp.resize(n+1);
    for(int i=1;i<=x;++i)
    {
        tmp[i]=s[n-i+1];
        //cout<<tmp[i]<<" "<<s[n-i+1]<<endl;
    }
    for(int i=x+1;i<=n;++i)
    {
        tmp[i]=s[i-x];
        //cout<<tmp[i]<<" "<<s[i-x]<<endl;
    }
    s=tmp;
}
int main()
{
    cin>>n>>s>>t;
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;++i)
    {
        ++cnt[s[i]-'a'];
        --cnt[t[i]-'a'];
    }
    for(int i=0;i<26;++i)
        if(cnt[i])
        {
            puts("-1");
            return 0;
        }
    for(int i=1;i<=n;++i)
    {
        int j=n-i+1;
        while(s[j]!=t[i])
            --j;
        if(j==n)
            continue;
        ans.emplace_back(n-j);
        shift(n-j);
        //cout<<s<<'\n';
        ans.emplace_back(1);
        shift(1);
        //cout<<s<<'\n';
        ans.emplace_back(n);
        shift(n);
        //cout<<s<<'\n';
    }
    cout<<ans.size()<<'\n';
    for(int i:ans)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}