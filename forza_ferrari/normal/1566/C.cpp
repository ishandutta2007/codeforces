#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,ans,n;
bool vis[100001];
string s1,s2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s1>>s2;
        ans=0;
        for(register int i=0;i<n;++i)
        {
            vis[i]=0;
            if((s1[i]^48)^(s2[i]^48))
            {
                ans+=2;
                continue;
            }
            if(s1[i]=='1')
            {
                if(i&&!vis[i-1]&&s1[i-1]=='0'&&s2[i-1]=='0')
                {
                    ++ans;
                    vis[i]=1;
                }
                continue;
            }
            ++ans;
            if(i&&!vis[i-1]&&s1[i-1]=='1'&&s2[i-1]=='1')
            {
                ++ans;
                vis[i]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}