#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int t,n;
string s[3],ans;
inline int calc(int x,int val)
{
    int cnt=0;
    for(auto i:s[x])
        cnt+=i-'0'==val;
    return cnt;
}
inline void build(int x,int y,int val)
{
    ans.clear();
    vector<int> v[2];
    v[0].emplace_back(-1);
    v[1].emplace_back(-1);
    for(int i=0;i<(int)s[x].length();++i)
        if(s[x][i]-'0'==val)
            v[0].emplace_back(i);
    for(int i=0;i<(int)s[y].length();++i)
        if(s[y][i]-'0'==val)
            v[1].emplace_back(i);
    v[0].emplace_back(s[x].length());
    v[1].emplace_back(s[y].length());
    int maxn=(int)max(v[0].size(),v[1].size());
    for(int i=1;i<maxn;++i)
    {
        int tmp=0;
        if(i<(int)v[0].size())
            tmp=v[0][i]-v[0][i-1]-1;
        if(i<(int)v[1].size())
            tmp=max(tmp,v[1][i]-v[1][i-1]-1);
        for(int j=1;j<=tmp;++j)
            ans.push_back((val^1)+'0');
        if(i+1!=maxn)
            ans.push_back(val+'0');
    }
    cout<<ans<<'\n';
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s[0]>>s[1]>>s[2];
        if(calc(0,0)>=n)
        {
            if(calc(1,0)>=n)
            {
                build(0,1,0);
                continue;
            }
            if(calc(2,0)>=n)
            {
                build(0,2,0);
                continue;
            }
        }
        if(calc(0,1)>=n)
        {
            if(calc(1,1)>=n)
            {
                build(0,1,1);
                continue;
            }
            if(calc(2,1)>=n)
            {
                build(0,2,1);
                continue;
            }
        }
        if(calc(1,0)>=n&&calc(2,0)>=n)
        {
            build(1,2,0);
            continue;
        }
        build(1,2,1);
    }
    return 0;
}