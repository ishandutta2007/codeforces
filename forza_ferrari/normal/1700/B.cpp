#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        if(s[0]!='9')
        {
            for(int i=0;i<n;++i)
                cout<<9-(s[i]-'0');
            cout<<'\n';
            continue;
        }
        bool flag=0;
        string ans;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]-'0'>1-flag)
            {
                ans.push_back(11-flag-(s[i]-'0')+'0');
                flag=1;
            }
            else
            {
                ans.push_back(1-flag-(s[i]-'0')+'0');
                flag=0;
            }
        }
        for(int i=n-1;i>=0;--i)
            cout<<ans[i];
        cout<<'\n';
    }
    return 0;
}