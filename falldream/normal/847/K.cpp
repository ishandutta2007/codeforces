#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define MN 300
#define P(x,y) make_pair(min(x,y),max(x,y))
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
map<pair<int,int>,int> s;
map<string,int> mp;
int n,A,B,k,f,cnt=0,last=-1,ans=0,c[MN+5],num=0;
string a,b;
int main()
{
    n=read();A=read();B=read();k=read();f=read();
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        if(!mp[a]) mp[a]=++cnt;
        if(!mp[b]) mp[b]=++cnt;
        int x=mp[a],y=mp[b],cost=(x==last)?B:A;
        ans+=cost;s[P(x,y)]+=cost;last=y;
    }
    for(map<pair<int,int>,int>::iterator it=s.begin();it!=s.end();it++)
        c[++num]=it->second;
    sort(c+1,c+num+1,greater<int>());
    for(int i=1;i<=k;++i)
        if(c[i]<=f) break;
        else ans-=c[i]-f;
    cout<<ans;
    return 0;
}