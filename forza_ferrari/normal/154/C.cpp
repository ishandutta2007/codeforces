#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
const unsigned long long base=1145141;
int n,m;
long long ans;
vector<int> v[1000001];
unordered_map<unsigned long long,int> mp[2000001];
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
inline unsigned long long calc(int x)
{
    unsigned long long res=0;
    for(auto i:v[x])
        res=res*base+(unsigned long long)i;
    return res;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    for(int i=1;i<=n;++i)
    {
        sort(v[i].begin(),v[i].end());
        ans+=mp[v[i].size()][calc(i)]++;
    }
    for(int i=1;i<=(m<<1);++i)
        mp[i].clear();
    for(int i=1;i<=n;++i)
    {
        v[i].emplace_back(i);
        sort(v[i].begin(),v[i].end());
        ans+=mp[v[i].size()][calc(i)]++;
    }
    cout<<ans<<'\n';
    return 0;
}