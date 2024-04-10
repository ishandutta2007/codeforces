#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,cnt[26];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        for(int i=0;i<26;++i)
            cnt[i]=0;
        for(int i=0;i<n;++i)
            ++cnt[s[i]-'a'];
        for(int i=0;i<n;++i)
            if(!--cnt[s[i]-'a'])
            {
                for(int j=i;j<n;++j)
                    cout<<s[j];
                break;
            }
        cout<<'\n';
    }
    return 0;
}