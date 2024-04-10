#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,ans[2];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        ans[0]=ans[1]=0;
        if(n&1)
        {
            if(s[1]<s[n])
            {
                ans[1]=s[1]-'a'+1;
                for(int i=2;i<=n;++i)
                    ans[0]+=s[i]-'a'+1;
            }
            else
            {
                ans[1]=s[n]-'a'+1;
                for(int i=1;i<n;++i)
                    ans[0]+=s[i]-'a'+1;
            }
        }
        else
            for(int i=1;i<=n;++i)
                ans[0]+=s[i]-'a'+1;
        if(ans[0]>ans[1])
            cout<<"Alice "<<ans[0]-ans[1]<<'\n';
        else
            cout<<"Bob "<<ans[1]-ans[0]<<'\n';
    }
    return 0;
}