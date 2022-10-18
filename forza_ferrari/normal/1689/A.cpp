#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int T,n,m,p;
string s,t,ans;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>p>>s>>t;
        ans.clear();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        s=" "+s;
        t=" "+t;
        int l=1,r=1,cnt[2]={0};
        while(l<=n&&r<=m)
        {
            if(s[l]<=t[r])
            {
                if(++cnt[0]<=p)
                {
                    ans.push_back(s[l++]);
                    cnt[1]=0;
                }
                else
                {
                    ans.push_back(t[r++]);
                    cnt[0]=0;
                    cnt[1]=1;
                }
            }
            else
            {
                if(++cnt[1]<=p)
                {
                    ans.push_back(t[r++]);
                    cnt[0]=0;
                }
                else
                {
                    ans.push_back(s[l++]);
                    cnt[1]=0;
                    cnt[0]=1;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}