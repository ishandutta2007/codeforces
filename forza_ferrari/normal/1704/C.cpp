#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,a[100001],ans;
vector<int> v;
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
        n=read(),ans=m=read();
        v.clear();
        for(int i=1;i<=m;++i)
            a[i]=read();
        sort(a+1,a+m+1);
        for(int i=1;i<m;++i)
            v.emplace_back(a[i+1]-a[i]-1);
        v.emplace_back(a[1]+n-a[m]-1);
        sort(v.begin(),v.end(),greater<int>());
        int cnt=0;
        for(auto i:v)
        {
            if(i-(cnt<<1)>1)
            {
                ans+=(cnt<<1)+1;
                cnt+=2;
            }
            else if(i-(cnt<<1)==1)
            {
                ans+=i-1;
                ++cnt;
            }
            else
                ans+=i;
        }
        cout<<ans<<'\n';
    }
    return 0;
}