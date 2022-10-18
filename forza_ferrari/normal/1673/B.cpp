#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,cnt;
bool vis[26];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        for(int i=0;i<26;++i)
            vis[i]=0;
        cnt=0;
        for(int i=0;i<n;++i)
            if(!vis[s[i]-'a'])
            {
                vis[s[i]-'a']=1;
                ++cnt;
            }
        bool flag=1;
        for(int i=0;i<cnt;++i)
        {
            for(int j=i+1;j<cnt;++j)
                if(s[i]==s[j])
                {
                    flag=0;
                    break;
                }
            if(!flag)
                break;
        }
        for(int i=cnt;i<n;++i)
            if(s[i]!=s[i%cnt])
            {
                flag=0;
                break;
            }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}