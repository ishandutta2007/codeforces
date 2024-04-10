#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int t,n,p[201],ans;
string s;
bool vis[201];
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        for(int i=1;i<=n;++i)
        {
            cin>>p[i];
            vis[i]=0;
        }
        ans=0;
        s=" "+s;
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                string str,tmp;
                for(int j=i;!vis[j];j=p[j])
                {
                    str.push_back(s[j]);
                    vis[j]=1;
                }
                tmp=str;
                tmp.push_back(tmp.front());
                tmp.erase(tmp.begin());
                int cnt=1;
                while(str!=tmp)
                {
                    tmp.push_back(tmp.front());
                    tmp.erase(tmp.begin());
                    ++cnt;
                }
                if(!ans)
                    ans=cnt;
                else
                    ans=ans/gcd(ans,cnt)*cnt;
            }
        cout<<ans<<'\n';
    }
    return 0;
}